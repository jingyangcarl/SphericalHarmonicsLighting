Spherical Harmonic Lighting
=============================

# Spherical Harmonic Lighting Result
![Tutorial 1](https://github.com/jingyangcarl/Resources/blob/master/QtOpenGLTutorials/Tutorial1/result.jpg)

# Solution Introduction
This solution implements a basic Graphics Engine using Qt and OpenGL. Graphics Engine interpretes all the geometrical objects including meshes, materials and transformations. OpenGLWidget

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.13.0

# Solution Documentation:
> Header Files
>
>> Graphics Engine
>>
>>> [Camera3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Camera3D.h): Camera3D class is an abstraction of a camera in 3D space;
>>>
>>>> void rotate(const QQuaternion& r): This function is used to rotate the camera;
>>>> 
>>>> void translate(const QVector3D& t): This function is used to translate the camera;
>>>> 
>>>> void scale(const float& s): This function is used to scale the camera;
>>>> 
>>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the camera;
>>>> 
>>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0): This function is used to set parameters for the vertex shader, fragment shader and etc.;
>>>
>>> [Group3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Group3D.h): Group3D class is used to manage different objects in a group;
>>>
>>>> void rotate(const QQuaternion& r): This function is used to rotate all the objects in a group, which calls Object3D::rotate(const QQuaternion&) for object rotation;
>>>> 
>>>> void translate(const QVector3D& t): This function is used to translate all the objects in a group, which calls Object3D::translate(const QVector3D&) for object translation;
>>>> 
>>>> void scale(const float& s): This function is used to scale all the objects in a group, which calls Object3D::scale(const float&) for object scaling;
>>>> 
>>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for all the objects in a group, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
>>>> 
>>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0): This function is used to draw all the objects in a group, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>>>
>>>> void addObject(Transformational* object): This function is used to add object into the group list. An initialization of its position is necessary;
>>>>
>>>> void delObject(Transformational* object): This function is used to remove an object from the group.
>>>
>>> [Material.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Material.h): Material class is used to define all parameters of a material, which should be defined as a subclass of QOpenGLTexture;
>>>
>>>> void setMaterialName(const QString & materialName): This function is used to set material name;
>>>> 
>>>> const QString& getMaterialName() const: This function is used to get material name;
>>>> 
>>>> void setAmbientColor(const QVector3D & ambientColor): This function is used to set ambient color for the material;
>>>> 
>>>> const QVector3D& getAmbientColor() const: This function is used to get ambient color of the material;
>>>> 
>>>> void setDiffuseColor(const QVector3D & diffuseColor): This function is used to set diffuse color for the material;
>>>> 
>>>> const QVector3D& getDiffuseColor() const: This function is used to get diffuse color of the material;
>>>> 
>>>> void setSpecularColor(const QVector3D & specularColor): This function is used to set specular color for the material;
>>>> 
>>>> const QVector3D& getSpecularColor() const: This function is used to get specular color of the material;
>>>> 
>>>> void setShinnes(const float & shinnes): This function is used to set shinnes for the material;
>>>> 
>>>> const float& getShinnes() const: This function is used to get shinnes of the material;
>>>> 
>>>> void setTexture(QOpenGLTexture * texture): This function is used to set texture for material;
>>>> 
>>>> void setTexture(const QImage & image): This function is used to set texture for material using an image;
>>>> 
>>>> void setTexture(const QString & path): This function is used to set texture for material using an image from path;
>>>> 
>>>> QOpenGLTexture * getTexture() const: This function is used to get texture of the material;
>>>> 
>>>> void bind(): This function is used to bind texture, which calls QOpenGLTexture::bind();
>>>> 
>>>> void bind(const uint index): This function is used to bind texture, which calls QOpenGLTexture::bind(uint);
>>>> 
>>>> bool create(): This function is used to create a default material;
>>>> 
>>>> bool createTexture(): This function is used to create a default texture;
>>>> 
>>>> void destroy(): This function is used to destroy the material, which calls QOpenGLTexture::destroy();
>>>> 
>>>> bool isCreated(): This function is used to tell if the material is created or not;
>>>> 
>>>> bool isTextureCreated(): This function is used to tell if the texture is created or not;
>>>> 
>>>> void setMinificationFilter(QOpenGLTexture::Filter filter): This function is used to set minification filter for mateiral, which calls QOpenGLTexture::setMinificationFilter(QOpenGLTexture::Filter);
>>>> 
>>>> void setMagnificationFilter(QOpenGLTexture::Filter filter): This function is used to set magnification filter for mateiral, which calls QOpenGLTexture::setMagnificationFilter(QOpenGLTexture::Filter);
>>>> 
>>>> void setWrapMode(QOpenGLTexture::WrapMode wrapMode): This function is used to set wrap mode for material, which calls QOpenGLTexture::setWrapMode(QOpenGLTexture::WrapMode);
>>>> 
>>>> void release(): This function is used to release the material;
>>>
>>> [MaterialLibrary.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/MaterialLibrary.h): MaterialLibrary class is used to manage all loaded materials;
>>>
>>>> void addMaterial(Material *material): This function is used to add material to the material list;
>>>> 
>>>> Material* getMaterial(const int index): This function is used to get material from the material list by its index;
>>>> 
>>>> Material* getMaterial(const QString & materialName): This function is used to get material from the material list by its name;
>>>> 
>>>> void loadMaterialFromFile(const QString & fileName): This function is used to load .mtl file froma given file path, the .mtl file should include material name [newmtl], ambience color [Ka], diffuse color [Kd], specular color [Ks], shinnes [Ns], diffuse map file name [map_Kd], etc. If the .mtl file doesn't have a diffuse map / texture file name [map_Kd], there will be a default diffuse map / texture generated when material or object is constructed;
>>>
>>> [Object3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object3D.h): Object3D class is an abstraction of a virtual object in 3D space;
>>>
>>>> Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material): This function is a constructor with vertices reference, indices reference, and material; If material is not provided, then create one; If only texture is not provided, then create texture;
>>>>
>>>> bool setTexture(const QImage& image): This function is used to set a new texture for the given object;
>>>> 
>>>> bool setTexture(QOpenGLTexture * texture): This function is used to set a given texture for the object;
>>>> 
>>>> QOpenGLTexture * getTexture() const: This function is used to get current texture of the object;
>>>> 
>>>> void rotate(const QQuaternion& r): This function is used to rotate the object;
>>>> 
>>>> void translate(const QVector3D& t): This function is used to translate the object;
>>>> 
>>>> void scale(const float& s): This function is used to scale the object;
>>>> 
>>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the object;
>>>> 
>>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw the object;
>>>
>>> [ObjectEngine3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/ObjectEngine3D.h): ObjectEngine3D class is used to manage all geometry of a 3D object including materials, positions;
>>>
>>>> void addObject(Object3D* object): This function is used to append an object to the end of the object list;
>>>> 
>>>> const Object3D* getObject(int index) const: This function is used to get an object from object list by its index;
>>>> 
>>>> void rotate(const QQuaternion& r): This function is used to rotate objects defined in the object engine, which calls Object3D::rotate(const QQuaternion&);
>>>> 
>>>> void translate(const QVector3D& t): This function is used to translate objects defined in the object engine, which calls Object3D::translate(const QVector3D&);
>>>> 
>>>> void scale(const float& s): This function is used to scale objects defined in the object engine, which calls Object3D::scale(const float&);
>>>> 
>>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform objects defined in the object engine, which calls Object3D::setGlobalTransform(const QMatrix4x4&);
>>>> 
>>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw objects defined in the object engine, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>>> 
>>>> void loadObjectFromFile(const QString & fileName): This function is used to load .obj file from a given filepath, the .obj file should include vertex coordinations [v], texture coordinations [vt], normals [vn], vertex indices of a given face [f], material library file name [mtllib], material name [usemtl]. If the .obj file doesn't have a material library file name [mtllib], there will be a default material generated when Object is contructed.
>>>
>>> [Skybox.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.h):
>>>
>>> [Transformational.h](): 
>>
>> OpenGLWidget
>>
>>> [Widget.h]():
>>
>> Qt Framework
>>
>>> [SphericalHarmonicsLighting.h]():
>>
>> Spherical Harmonics
>>
>>>[SphericalHarmonicsSampler.h]():
>>
>
> Shader
>>
>> Object Shader
>>
>>> [Object.vsh]():
>>>
>>> [Object.fsh]():
>>
>> Skybox Shader
>>
>>> [Skybox.vsh]():
>>>
>>> [Skybox.fsh]():
>>
>> Test Shader
>>
>>> [TestShader.vsh]():
>>>
>>> [TestShader.fsh]():
>>
>
> Source Files
>
>> Graphics Engine
>>
>>> [Camera3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Camera3D.cpp): implements Camera3D.h
>>>
>>> [Group3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Group3D.cpp): implements Group3D.h
>>>
>>> [Material.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Material.cpp): implements Material.h
>>>
>>> [MaterialLibrary.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/MaterialLibrary.cpp): implements MaterialLibrary.h
>>>
>>> [Object3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object3D.cpp): implements Object3D.h
>>>
>>> [ObjectEngine3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/ObjectEngine3D.cpp): implements ObjectEngine3D.h
>>>
>>> [Skybox.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.cpp): implements skybox.h
>>
>> OpenGLWidget
>>
>>> [Widget.cpp](): implements Widget.h
>>>
>>> [WidgetCallback.cpp](): implements all callback functions in Widget.h
>>>
>>> [WidgetParameter.cpp](): implements all parameter setting functions in Widget.h
>>
>> QtFrameWork
>>
>>> [QtInitialization.cpp](): implements all Qt initialization functions in SphericalHarmonicsLighting.h
>>>
>>> [QtSlotFunction.cpp](): implements all Qt Slot functions in SphericalHarmonicsLighting.h
>>>
>>> [SphericalHarmonicsLighting.cpp](): implements SphericalHarmonicsLighting.h
>>
>> Spherical Harmonics
>>
>>> [SphericalHarmonicsEvaluation.cpp](): implements all spherical harmonic lighting coefficients evaluation in SphericalHarmonicsSampler.h
>>>
>>> [SphericalHarmonicsSampler.cpp](): implements SphericalHarmonicsSampler.cpp
>>
>> [main.cpp]()
>

# Solution Hierarchy:
```
│   .gitattributes
│   .gitignore
│   CodeMap.dgml
│   README.md
│   SphericalHarmonicsLighting.sln
│
├───Result
│       Diffuse_SH.mp4
│       Glass.mp4
│       Mirror.mp4
│
└───SphericalHarmonicsLighting
    │   Camera3D.cpp
    │   Camera3D.h
    │   Group3D.cpp
    │   Group3D.h
    │   main.cpp
    │   Material.cpp
    │   Material.h
    │   MaterialLibrary.cpp
    │   MaterialLibrary.h
    │   Object.fsh
    │   Object.vsh
    │   Object3D.cpp
    │   Object3D.h
    │   ObjectEngine3D.cpp
    │   ObjectEngine3D.h
    │   QtInitialization.cpp
    │   QtSlotFunction.cpp
    │   Shader.fsh
    │   Shader.vsh
    │   Skybox.cpp
    │   Skybox.fsh
    │   Skybox.h
    │   Skybox.vsh
    │   SphericalHarmonicsEvaluation.cpp
    │   SphericalHarmonicsLighting.cpp
    │   SphericalHarmonicsLighting.h
    │   SphericalHarmonicsLighting.qrc
    │   SphericalHarmonicsLighting.ui
    │   SphericalHarmonicsLighting.vcxproj
    │   SphericalHarmonicsLighting.vcxproj.filters
    │   SphericalHarmonicsLighting.vcxproj.user
    │   SphericalHarmonicsSampler.cpp
    │   SphericalHarmonicsSampler.h
    │   Transformational.h
    │   Widget.cpp
    │   Widget.h
    │   WidgetCallback.cpp
    │   WidgetParameter.cpp
    │
    ├───GeneratedFiles
    │   │   qrc_SphericalHarmonicsLighting.cpp
    │   │   ui_SphericalHarmonicsLighting.h
    │   │
    │   ├───Debug
    │   │       moc_SphericalHarmonicsLighting.cpp
    │   │
    │   └───Release
    │           moc_SphericalHarmonicsLighting.cpp
    │
    └───Resources
        ├───Equirectangular
        │   ├───House
        │   ├───LightStage
        │   └───LightStageII
        │
        ├───Model
        │   │   bunny.obj
        │   │   dragon.obj
        │   │   estrellica.obj
        │   │   laurana.obj
		│	│
        │   ├───Polygon Mesh
        │   └───Triangle Mesh
        │       ├───Cube
        │       ├───Estrellica
        │       ├───Human
        │       ├───Intergalactic Spaceship
        │       ├───Max Curato
        │       ├───Pyramid
        │       ├───Sphere
        │       └───Teapot
        │
        ├───Output
        │
        └───Skybox
            ├───00
            ├───01
            ├───02
            ├───03
            ├───AHouse
            ├───ALightStage
            ├───ALightStageII
            ├───ALightStageSample
            ├───CNTower
            ├───CoitTower2
            ├───Footballfield2
            ├───FortPoint
            ├───GoldenGateBridge3
            ├───hornstullsstrand
            ├───House
            ├───LancellottiChapel
            ├───Lycksele3
            ├───MarriottMadisonWest
            ├───SaintLazarusChurch2
            ├───SanFrancisco
            ├───Sodermalmsallen
            ├───Stairs
            ├───Tallinn
            └───Yokohama

```