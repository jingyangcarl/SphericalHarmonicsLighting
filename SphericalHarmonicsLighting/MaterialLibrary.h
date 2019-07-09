#pragma once
#include "Material.h"
#include <qfile.h>
#include <qfileinfo.h>
#include <qtextstream.h>
#include <qdebug.h>

class MaterialLibrary {
public:
	MaterialLibrary();
	~MaterialLibrary();

	void addMaterial(Material *material);
	Material* getMaterial(int index);
	Material* getMaterial(const QString & materialName);
	void loadMaterialFromFile(const QString & fileName);

private:
	QVector<Material*> materials;
};

