#include "MaterialLibrary.h"

MaterialLibrary::MaterialLibrary() {
}

MaterialLibrary::~MaterialLibrary() {
}

void MaterialLibrary::addMaterial(Material * material) {
	if (!material) return;

	for (int i = 0; i < materials.size(); i++) {
		if (materials[i] == material) {
			return;
		}
	}

	materials.append(material);
}

Material * MaterialLibrary::getMaterial(int index) {
	if (index < 0 || index >= materials.size()) return 0;
	return materials[index];
}

Material * MaterialLibrary::getMaterial(const QString & materialName) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i]->getMaterialName() == materialName) {
			return materials[i];
		}
	}
	return 0;
}

void MaterialLibrary::loadMaterialFromFile(const QString & fileName) {
	// Read .mtl file, where the file includes
	// newmtl [name]
	// Ka [AmbienceColor]
	// Kd [DiffuseColor]
	// Ks [SpecularColor]
	// d []
	// Ns [Shinnes]
	// illum []
	// map_Kd [diffuseMap]

	QFile inputFile(fileName);
	
	if (!inputFile.open(QIODevice::ReadOnly)) return;

	QTextStream input(&inputFile);
	QFileInfo fileInfo(inputFile);

	// data to load
	Material* material = 0;

	while (!input.atEnd()) {
		QString line = input.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "newmtl") {
			// add last material
			addMaterial(material);

			// load next material
			material = new Material();
			material->setMaterialName(list[1]);
			continue;
		}
		else if (list[0] == "Ka") {
			if (list.size() < 4) {
				qDebug() << "Carl::MaterialLibrary::loadMaterialFromFile::Ka error: not enough parameters";
				exit(-1);
			}
			material->setAmbientColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
			continue;
		}
		else if (list[0] == "Kd") {
			if (list.size() < 4) {
				qDebug() << "Carl::MaterialLibrary::loadMaterialFromFile::Kd error: not enough parameters";
				exit(-1);
			}
			material->setDiffuseColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
			continue;
		}
		else if (list[0] == "Ks") {
			if (list.size() < 4) {
				qDebug() << "Carl::MaterialLibrary::loadMaterialFromFile::Ks error: not enough parameters";
				exit(-1);
			}
			material->setSpecularColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
			continue;
		}
		else if (list[0] == "Ns") {
			if (list.size() < 2) {
				qDebug() << "Carl::MaterialLibrary::loadMaterialFromFile::Ns error: not enough parameters";
				exit(-1);
			}
			material->setShinnes(list[1].toFloat());
			continue;
		}
		else if (list[0] == "map_Kd") {
			if (list.size() < 2) {
				qDebug() << "Carl::MaterialLibrary::loadMaterialFromFile::map_Kd error: not enough parameters";
				exit(-1);
			}
			material->setDiffuseMap(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
			continue;
		}
	}

	// add last material
	addMaterial(material);

	// close file
	inputFile.close();
}
