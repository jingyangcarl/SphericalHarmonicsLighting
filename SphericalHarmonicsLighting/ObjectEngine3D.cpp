#include "ObjectEngine3D.h"

ObjectEngine3D::ObjectEngine3D() {
}

ObjectEngine3D::~ObjectEngine3D() {
}

void ObjectEngine3D::rotate(const QQuaternion & r) {
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->rotate(r);
	}
}

void ObjectEngine3D::translate(const QVector3D & t) {
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->translate(t);
	}
}

void ObjectEngine3D::scale(const float & s) {
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->scale(s);
	}
}

void ObjectEngine3D::setGlobalTransform(const QMatrix4x4 & g) {
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->setGlobalTransform(g);
	}
}

void ObjectEngine3D::draw(QOpenGLShaderProgram * shaderProgram, QOpenGLFunctions * functions) {
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->draw(shaderProgram, functions);
	}
}
void ObjectEngine3D::addObject(Object3D * object) {
	if (!object) return;
	for (QVector<Object3D*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		if ((*iter) == object) {
			return;
		}
	}
	objects.append(object);
}

const Object3D * ObjectEngine3D::getObject(int index) const {
	if (index < 0 || index >= objects.size()) return 0;
	return objects[index];
}

void ObjectEngine3D::loadObjectFromFile(const QString & filePath) {
	// Read .obj file, where the file includes
	// mtllib [.mtl name]
	// usemtl [materialName]
	// v [verCoords]
	// vt [texCoords]
	// vn [normals]
	// f [verIndices]

	QFile inputFile(filePath);

	if (!inputFile.open(QIODevice::ReadOnly)) return;

	QTextStream input(&inputFile);
	QFileInfo fileInfo(inputFile);

	// data to load
	QVector<QVector3D> verCoords;
	QVector<QVector2D> texCoords;
	QVector<QVector3D> normals;
	QVector<Vertex> vertices;
	QVector<GLuint> indices;
	Object3D* object = 0;
	QString materialName;

	while (!input.atEnd()) {
		QString line = input.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "mtllib") {
			if (list.size() < 2) {
				qDebug() << "Carl::ObjectEngine3D::loadMaterialFromFile::mtllib error: not enough parameters";
				exit(-1);
			}
			materials.loadMaterialFromFile(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
			continue;
		}
		else if (list[0] == "usemtl") {
			if (list.size() < 2) {
				qDebug() << "Carl::ObjectEngine3D::loadMaterialFromFile::usemtl error: not enough parameters";
				exit(-1);
			}
			if (object) object = new Object3D(vertices, indices, materials.getMaterial(materialName));
			materialName = list[1];
			addObject(object);

			// init for the next object
			object = new Object3D();
			continue;
		}
		else if (list[0] == "v") {
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::v: not enough parameters";
				exit(-1);
			}
			verCoords << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
			continue;
		}
		else if (list[0] == "vt") {
			if (list.size() < 3) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::vt: not enough parameters";
				exit(-1);
			}
			texCoords << QVector2D(list[1].toFloat(), list[2].toFloat());
			continue;
		} 
		else if (list[0] == "vn") {
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::vn: not enough parameters";
				exit(-1);
			}
			normals << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
			continue;
		}
		else if (list[0] == "f") {
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::f: not enough parameters";
				exit(-1);
			}
			else if (list.size() > 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::f: not triangle mesh";
				exit(-1);
			}
			for (int i = 1; i <= 3; i++) {
				QStringList sublist = list[i].split("/");
				if (sublist.size() == 3) {
					vertices << Vertex(verCoords[sublist[0].toLong() - 1], texCoords[sublist[1].toLong() - 1], normals[sublist[2].toLong() - 1]);
					indices << indices.size();
				}
				else if (sublist.size() == 2) {
					qDebug() << "WARNING::Carl::ObjectEngine3D::loadMaterialFromFile::f: lack texCoords";
					vertices << Vertex(verCoords[sublist[0].toLong() - 1], QVector2D(0.0, 0.0), normals[sublist[2].toLong() - 1]);
					indices << indices.size();
				}
			}
			continue;
		}
	}

	// add last object
	if (object) object = new Object3D(vertices, indices, materials.getMaterial(materialName));
	addObject(object);

	// close file
	inputFile.close();
}
