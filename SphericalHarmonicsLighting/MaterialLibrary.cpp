#include "MaterialLibrary.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
MaterialLibrary::MaterialLibrary() {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
MaterialLibrary::~MaterialLibrary() {
	qDeleteAll(materials);
}

/*
Description:
	This function is used to add material to the material list;
Input:
	@ Material * mateiral: a given material;
Output:
	@ void returnValue: void;	
*/
void MaterialLibrary::addMaterial(Material * material) {
	if (!material) return;

	for (int i = 0; i < materials.size(); i++) {
		if (materials[i] == material) {
			return;
		}
	}

	materials.append(material);
}

/*
Description:
	this function is used to get material from the material list by its index;
Input:
	@ const int index: a index refer to the material;
Output:
	@ Material * returnValue: a material;
*/
Material * MaterialLibrary::getMaterial(const int index) {
	if (index < 0 || index >= materials.size()) return 0;
	return materials[index];
}

/*
Description:
	This function is used to get material from the material list by its name;
Input:
	@ const QString & materialName: a name refer to the material;
Output:
	@ Material * returnValue: a material;
*/
Material * MaterialLibrary::getMaterial(const QString & materialName) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i]->getMaterialName() == materialName) {
			return materials[i];
		}
	}
	return 0;
}

/*
Description:
	This function is used to load .mtl file froma given file path, the .mtl file should include
	material name [newmtl], ambience color [Ka], diffuse color [Kd], specular color [Ks], shinnes [Ns], diffuse map file name [map_Kd], etc.
	If the .mtl file doesn't have a diffuse map / texture file name [map_Kd], there will be a default diffuse map / texture generated when material or object is constructed;
Input:
	@ const QString & fileName: the path refer to the .mtl file
Output:
	@ void returnValue: void;
*/
void MaterialLibrary::loadMaterialFromFile(const QString & fileName) {

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
			material->create();
			material->setTexture(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
			continue;
		}
	}

	// add last material
	addMaterial(material);

	// close file
	inputFile.close();
}
