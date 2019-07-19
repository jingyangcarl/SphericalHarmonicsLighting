#include "ObjectEngine3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
ObjectEngine3D::ObjectEngine3D() {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
ObjectEngine3D::~ObjectEngine3D() {
}

/*
Description:
	This function is used to append an object to the end of the object list;
Input:
	@ Object3D * object: the object;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::addObject(Object3D * object) {
	if (!object) return;
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		if ((*iter) == object) {
			return;
		}
	}
	objects.append(object);
}

/*
Description:
	This function is used to get an object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: a pointer to an object;
*/
const Object3D * ObjectEngine3D::getObject(int index) const {
	if (index < 0 || index >= objects.size()) return 0;
	return objects[index];
}

/*
Description:
	This function is used to get the total number of vertex coordinations of a given object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: total number of vertex coordinations;
*/
const int ObjectEngine3D::getVerCoordCount(const int index) const {
	if (index >= objects.size() || index < 0) {
		return -1;
	}
	return objects[index]->getVerCoordCount();
}

/*
Description:
	This function is used to get the total number of texture coordinations of a given object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: total number of texture coordinations;
*/
const int ObjectEngine3D::getTexCoordCount(const int index) const {
	if (index >= objects.size() || index < 0) {
		return -1;
	}
	return objects[index]->getTexCoordCount();
}

/*
Description:
	This function is used to get the total number of normals of a given object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: total number of normals;
*/
const int ObjectEngine3D::getNormalCount(const int index) const {
	if (index >= objects.size() || index < 0) {
		return -1;
	}
	return objects[index]->getNormalCount();
}

/*
Description:
	This function is used to get the total number of faces of a given object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: total number of faces;
*/
const int ObjectEngine3D::getFaceCount(const int index) const {
	if (index >= objects.size() || index < 0) {
		return -1;
	}
	return objects[index]->getFaceCount();
}

/*
Description:
	This function is used to rotate objects defined in the object engine, which calls Object3D::rotate(const QQuaternion&);
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::rotate(const QQuaternion & r) {
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->rotate(r);
	}
}

/*
Description:
	This function is used to translate objects defined in the object engine, which calls Object3D::translate(const QVector3D&);
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::translate(const QVector3D & t) {
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->translate(t);
	}
}

/*
Description:
	This function is used to scale objects defined in the object engine, which calls Object3D::scale(const float&);
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::scale(const float & s) {
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->scale(s);
	}
}

/*
Description:
	This function is used to set the global transform objects defined in the object engine, which calls Object3D::setGlobalTransform(const QMatrix4x4&);
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::setGlobalTransform(const QMatrix4x4 & g) {
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->setGlobalTransform(g);
	}
}

/*
Description:
	This function is used to draw objects defined in the object engine, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::draw(QOpenGLShaderProgram * shaderProgram, QOpenGLFunctions * functions) {
	for (auto iter = objects.begin(); iter != objects.end(); iter++) {
		(*iter)->draw(shaderProgram, functions);
	}
}

/*
Description:
	This function is used to load .obj file from a given filepath, the .obj file should include 
	vertex coordinations [v], texture coordinations [vt], normals [vn], vertex indices of a given face [f], material library file name [mtllib], material name [usemtl].
	If the .obj file doesn't have a material library file name [mtllib], there will be a default material generated when Object is contructed.
Input:
	@ const QString & filePath: the path refer to the .obj file
Output:
	@void returnValue: void;
*/
void ObjectEngine3D::loadObjectFromFile(const QString & filePath) {

	QFile inputFile(filePath);

	if (!inputFile.open(QIODevice::ReadOnly)) {
		qDebug() << "ERROR::ObjectEngine3D::loadObjectFromFile::inputFile: input file is not opened;";
		return;
	}

	QTextStream input(&inputFile);
	QFileInfo fileInfo(inputFile);

	// data to load
	Object3D* object = 0;
	QVector<QVector3D> verCoords;
	QVector<QVector2D> texCoords;
	QVector<QVector3D> normals;
	QVector<Vertex> vertices;
	QVector<GLuint> indices;
	QString materialName;

	// count
	int verCoordCount(0);
	int texCoordCount(0);
	int normalCount(0);
	int faceCount(0);

	while (!input.atEnd()) {
		QString line = input.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "mtllib") {
			// mtllib [material library file name]
			if (list.size() < 2) {
				qDebug() << "Carl::ObjectEngine3D::loadMaterialFromFile::mtllib error: not enough parameters";
				exit(-1);
			}
			materials.loadMaterialFromFile(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
			continue;
		}
		else if (list[0] == "usemtl") {
			// usemtl [material from material library]
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
			// v [xCoord] [yCoord] [zCoord]
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::v: not enough parameters";
				exit(-1);
			}
			verCoords << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
			verCoordCount++;
			continue;
		}
		else if (list[0] == "vt") {
			// vt [uCoord] [vCoord]
			if (list.size() < 3) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::vt: not enough parameters";
				exit(-1);
			}
			texCoords << QVector2D(list[1].toFloat(), list[2].toFloat());
			texCoordCount++;
			continue;
		} 
		else if (list[0] == "vn") {
			// vn [xCoord] [yCoord] [zCoord]
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::vn: not enough parameters";
				exit(-1);
			}
			normals << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
			normalCount++;
			continue;
		}
		else if (list[0] == "f") {
			if (list.size() < 4) {
				qDebug() << "ERROR::Carl::ObjectEngine3D::loadMaterialFromFile::f: not enough parameters";
				exit(-1);
			}

			if (list.size() == 4) {
				// f [indices1] [indices2] [indices3]
				for (int i = 1; i <= 3; i++) {
					QStringList sublist = list[i].split("/");
					if (sublist.size() == 3) {
						if (sublist[1] == "") {
							// f [] [] []
							vertices << Vertex(verCoords[sublist[0].toLong() - 1], QVector2D(0.5, 0.5), normals[sublist[2].toLong() - 1]);
							indices << indices.size();
						} else {
							vertices << Vertex(verCoords[sublist[0].toLong() - 1], texCoords[sublist[1].toLong() - 1], normals[sublist[2].toLong() - 1]);
							indices << indices.size();
						}
					} else if (sublist.size() == 2) {
						exit(-1);
					}
				}
			}
			else if (list.size() == 5) {
				// f [indices1] [indices2] [indices3] [indices4]
				qDebug() << "WARNING::Carl::ObjectEngine3D::loadMaterialFromFile::f: not triangle mesh";
				exit(-1);
			}
			faceCount++;
			continue;
		}
	}

	// add last object
	object = new Object3D(vertices, indices, materials.getMaterial(materialName));
	addObject(object);

	// close file
	inputFile.close();
}
