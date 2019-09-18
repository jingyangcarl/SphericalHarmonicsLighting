Spherical Harmonic Lighting
=============================

## Spherical Harmonic Lighting Result
| Scene | Scene 1 | Scene 2 | Scene 3 |
| :---: | :-----: | :-----: | :-----: | 
| Spherical Harmonic Lighting | [![Spherical Harmonic Lighting Scene 1](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_SphericalHarmonicsLighting_Scene_1.gif)](https://www.youtube.com/watch?v=2R7f_KR2g5c) | [![Spherical Harmonic Lighting Scene 2](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_SphericalHarmonicsLighting_Scene_2.gif)](https://www.youtube.com/watch?v=wvXcyf_CwMM) | [![Spherical Harmonic Lighting Scene 3](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_SphericalHarmonicsLighting_Scene_3.gif)](https://www.youtube.com/watch?v=sL7c8y7MrPg) |
| Glass Lighting | [![Glass Lighting Scene 1](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_GlassLighting_Scene_1.gif)](https://www.youtube.com/watch?v=-c_BF3ifxa8) | [![Glass Lighting Scene 2](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_GlassLighting_Scene_2.gif)](https://www.youtube.com/watch?v=O0RZkTBJpsc) | [![Glass Lighting Scene 3](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_GlassLighting_Scene_3.gif)](https://www.youtube.com/watch?v=dFXXyniNXd8) |
| Mirror Lighting | [![Mirror Lighting Scene 1](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_MirrorLighting_Scene_1.gif)](https://www.youtube.com/watch?v=WrSahuWK1mk) | [![Mirror Lighting Scene 2](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_MirrorLighting_Scene_2.gif)](https://www.youtube.com/watch?v=Edo2vsf7mW4) | [![Mirror Lighting Scene 3](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Sphere_MirrorLighting_Scene_3.gif)](https://www.youtube.com/watch?v=SWxjBzJcLN0) |

## Solution Introduction
This solution implements a basic Graphics Engine using Qt and OpenGL. Graphics Engine interpretes all the geometrical objects including meshes, materials and transformations. OpenGLWidget

## Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.13.0

## Solution Documentation:
> Header Files
>
>> Graphics Engine
>>
>>> [Camera3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Camera3D.h): Camera3D class is an abstraction of a camera in 3D space;
>>>
>>> [Group3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Group3D.h): Group3D class is used to manage different objects in a group;
>>>
>>> [Material.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Material.h): Material class is used to define all parameters of a material, which should be defined as a subclass of QOpenGLTexture;
>>>
>>> [MaterialLibrary.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/MaterialLibrary.h): MaterialLibrary class is used to manage all loaded materials;
>>>
>>> [Object3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object3D.h): Object3D class is an abstraction of a virtual object in 3D space;
>>>
>>> [ObjectEngine3D.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/ObjectEngine3D.h): ObjectEngine3D class is used to manage all geometry of a 3D object including materials, positions;
>>>
>>> [Skybox.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.h): Skybox class is derived from Object3D and add materials, spherical harmonic coefficients and etc.
>>>
>>> [Transformational.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Transformational.h): An abstract class used as a blueprint;
>>>
>>>> virtual void rotate(const QQuaternion& r) = 0;
>>>>
>>>> virtual void translate(const QVector3D& t) = 0;
>>>> 
>>>> virtual void scale(const float& s) = 0;
>>>> 
>>>> virtual void setGlobalTransform(const QMatrix4x4& g) = 0;
>>>> 
>>>> virtual void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) = 0;
>>>
>>
>> OpenGLWidget
>>
>>> [Widget.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Widget.h): Widget class is a customed class for QOpenGLWidget, which is used to define all the variables related for shaders, object rendering, and event functions;
>>
>> Qt Framework
>>
>>> [SphericalHarmonicsLighting.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/SphericalHarmonicsLighting.h): SphericalHarmonicsLighting class is used to define Qt UI framework, where all the widgets can be accessed via Ui::SphericalHarmonicsLightingClass;
>>
>> Spherical Harmonics
>>
>>>[SphericalHarmonicsSampler.h](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/SphericalHarmonicsSampler.h): SphericalHarmonicsSampler class is used to conduct spherical harmonics sampling, coefficients evaluations, where the coefficients are used to pass to the shaders for fragment rendering;
>>
>
> Shader
>>
>> Object Shader
>>
>>> [Object.vsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object.vsh): vertex shader used to render object;
>>>
>>> [Object.fsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object.fsh): fragment shader used to render object;
>>
>> Skybox Shader
>>
>>> [Skybox.vsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.vsh): vertex shader used to render skybox;
>>>
>>> [Skybox.fsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.fsh): fragment shader used to render skybox;
>>
>> Test Shader
>>
>>> [TestShader.vsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/TestShader.vsh): a test vertex shader;
>>>
>>> [TestShader.fsh](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/TestShader.fsh): a text fragment shader;
>>
>
> Source Files
>
>> Graphics Engine
>>
>>> [Camera3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Camera3D.cpp): implements Camera3D.h;
>>>
>>>> void Camera3D::rotate(const QQuaternion& r): This function is used to rotate the camera;
>>>> 
>>>> void Camera3D::translate(const QVector3D& t): This function is used to translate the camera;
>>>> 
>>>> void Camera3D::scale(const float& s): This function is used to scale the camera;
>>>> 
>>>> void Camera3D::setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the camera;
>>>> 
>>>> void Camera3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0): This function is used to set parameters for the vertex shader, fragment shader and etc.;
>>>
>>> [Group3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Group3D.cpp): implements Group3D.h;
>>>
>>>> void Group3D::rotate(const QQuaternion& r): This function is used to rotate all the objects in a group, which calls Object3D::rotate(const QQuaternion&) for object rotation;
>>>> 
>>>> void Group3D::translate(const QVector3D& t): This function is used to translate all the objects in a group, which calls Object3D::translate(const QVector3D&) for object translation;
>>>> 
>>>> void Group3D::scale(const float& s): This function is used to scale all the objects in a group, which calls Object3D::scale(const float&) for object scaling;
>>>> 
>>>> void Group3D::setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for all the objects in a group, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
>>>> 
>>>> void Group3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0): This function is used to draw all the objects in a group, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>>>
>>>> void Group3D::addObject(Transformational* object): This function is used to add object into the group list. An initialization of its position is necessary;
>>>>
>>>> void Group3D::delObject(Transformational* object): This function is used to remove an object from the group.
>>>
>>> [Material.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Material.cpp): implements Material.h;
>>>
>>>> void Material::setMaterialName(const QString & materialName): This function is used to set material name;
>>>> 
>>>> const QString& Material::getMaterialName() const: This function is used to get material name;
>>>> 
>>>> void Material::setAmbientColor(const QVector3D & ambientColor): This function is used to set ambient color for the material;
>>>> 
>>>> const QVector3D& Material::getAmbientColor() const: This function is used to get ambient color of the material;
>>>> 
>>>> void Material::setDiffuseColor(const QVector3D & diffuseColor): This function is used to set diffuse color for the material;
>>>> 
>>>> const QVector3D& Material::getDiffuseColor() const: This function is used to get diffuse color of the material;
>>>> 
>>>> void Material::setSpecularColor(const QVector3D & specularColor): This function is used to set specular color for the material;
>>>> 
>>>> const QVector3D& Material::getSpecularColor() const: This function is used to get specular color of the material;
>>>> 
>>>> void Material::setShinnes(const float & shinnes): This function is used to set shinnes for the material;
>>>> 
>>>> const float& Material::getShinnes() const: This function is used to get shinnes of the material;
>>>> 
>>>> void Material::setTexture(QOpenGLTexture * texture): This function is used to set texture for material;
>>>> 
>>>> void Material::setTexture(const QImage & image): This function is used to set texture for material using an image;
>>>> 
>>>> void Material::setTexture(const QString & path): This function is used to set texture for material using an image from path;
>>>> 
>>>> QOpenGLTexture * Material::getTexture() const: This function is used to get texture of the material;
>>>> 
>>>> void Material::bind(): This function is used to bind texture, which calls QOpenGLTexture::bind();
>>>> 
>>>> void Material::bind(const uint index): This function is used to bind texture, which calls QOpenGLTexture::bind(uint);
>>>> 
>>>> bool Material::create(): This function is used to create a default material;
>>>> 
>>>> bool Material::createTexture(): This function is used to create a default texture;
>>>> 
>>>> void Material::destroy(): This function is used to destroy the material, which calls QOpenGLTexture::destroy();
>>>> 
>>>> bool Material::isCreated(): This function is used to tell if the material is created or not;
>>>> 
>>>> bool Material::isTextureCreated(): This function is used to tell if the texture is created or not;
>>>> 
>>>> void Material::setMinificationFilter(QOpenGLTexture::Filter filter): This function is used to set minification filter for mateiral, which calls QOpenGLTexture::setMinificationFilter(QOpenGLTexture::Filter);
>>>> 
>>>> void Material::setMagnificationFilter(QOpenGLTexture::Filter filter): This function is used to set magnification filter for mateiral, which calls QOpenGLTexture::setMagnificationFilter(QOpenGLTexture::Filter);
>>>> 
>>>> void Material::setWrapMode(QOpenGLTexture::WrapMode wrapMode): This function is used to set wrap mode for material, which calls QOpenGLTexture::setWrapMode(QOpenGLTexture::WrapMode);
>>>> 
>>>> void Material::release(): This function is used to release the material;
>>>
>>> [MaterialLibrary.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/MaterialLibrary.cpp): implements MaterialLibrary.h;
>>>
>>>> void MaterialLibrary::addMaterial(Material *material): This function is used to add material to the material list;
>>>> 
>>>> Material* MaterialLibrary::getMaterial(const int index): This function is used to get material from the material list by its index;
>>>> 
>>>> Material* MaterialLibrary::getMaterial(const QString & materialName): This function is used to get material from the material list by its name;
>>>> 
>>>> void MaterialLibrary::loadMaterialFromFile(const QString & fileName): This function is used to load .mtl file froma given file path, the .mtl file should include material name [newmtl], ambience color [Ka], diffuse color [Kd], specular color [Ks], shinnes [Ns], diffuse map file name [map_Kd], etc. If the .mtl file doesn't have a diffuse map / texture file name [map_Kd], there will be a default diffuse map / texture generated when material or object is constructed;
>>>
>>> [Object3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Object3D.cpp): implements Object3D.h;
>>>
>>>> Object3D::Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material): This function is a constructor with vertices reference, indices reference, and material; If material is not provided, then create one; If only texture is not provided, then create texture;
>>>>
>>>> bool Object3D::setTexture(const QImage& image): This function is used to set a new texture for the given object;
>>>> 
>>>> bool Object3D::setTexture(QOpenGLTexture * texture): This function is used to set a given texture for the object;
>>>> 
>>>> QOpenGLTexture * Object3D::getTexture() const: This function is used to get current texture of the object;
>>>> 
>>>> void Object3D::rotate(const QQuaternion& r): This function is used to rotate the object;
>>>> 
>>>> void Object3D::translate(const QVector3D& t): This function is used to translate the object;
>>>> 
>>>> void Object3D::scale(const float& s): This function is used to scale the object;
>>>> 
>>>> void Object3D::setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the object;
>>>> 
>>>> void Object3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw the object;
>>>
>>> [ObjectEngine3D.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/ObjectEngine3D.cpp): implements ObjectEngine3D.h;
>>>
>>>> void ObjectEngine3D::addObject(Object3D* object): This function is used to append an object to the end of the object list;
>>>> 
>>>> const Object3D* ObjectEngine3D::getObject(int index) const: This function is used to get an object from object list by its index;
>>>> 
>>>> void ObjectEngine3D::rotate(const QQuaternion& r): This function is used to rotate objects defined in the object engine, which calls Object3D::rotate(const QQuaternion&);
>>>> 
>>>> void ObjectEngine3D::translate(const QVector3D& t): This function is used to translate objects defined in the object engine, which calls Object3D::translate(const QVector3D&);
>>>> 
>>>> void ObjectEngine3D::scale(const float& s): This function is used to scale objects defined in the object engine, which calls Object3D::scale(const float&);
>>>> 
>>>> void ObjectEngine3D::setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform objects defined in the object engine, which calls Object3D::setGlobalTransform(const QMatrix4x4&);
>>>> 
>>>> void ObjectEngine3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw objects defined in the object engine, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>>> 
>>>> void ObjectEngine3D::loadObjectFromFile(const QString & fileName): This function is used to load .obj file from a given filepath, the .obj file should include vertex coordinations [v], texture coordinations [vt], normals [vn], vertex indices of a given face [f], material library file name [mtllib], material name [usemtl]. If the .obj file doesn't have a material library file name [mtllib], there will be a default material generated when Object is contructed.
>>>
>>> [Skybox.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Skybox.cpp): implements skybox.h;
>>>
>>>> bool Skybox::loadCube(int width, QVector<Vertex>& desVertices, QVector<GLuint>& desIndices): This function is used to load graphics data for skybox, including vertex data and index data;
>>>> 
>>>> bool Skybox::loadTextures(): This function is used to load skybox images from directory and generate corresponding textures. The images will be pass to Spherical harmonics Sampler for spherical harmonic coefficienets.
>>>> 
>>>> bool Skybox::loadMaterial(): This function is used to load material for the skybox;
>>>> 
>>>> bool Skybox::setTexture(QImage& image): This function is used to change the texture of the skybox, which calls Object3D::setTexture(QImage &) for texture setting;
>>>> 
>>>> bool Skybox::setTexture(QOpenGLTexture * texture): This function is used to change the texture of the skybox, which calls Object3D::setTexture(QImage &) for texture setting;
>>>> 
>>>> bool Skybox::setTexture(int index): This funciton is an overloaded function, which sets the texture getting from the loaded texture list by its index;
>>>> 
>>>> QOpenGLTexture * Skybox::getTexture() const: This funciton is used to get the current texture;
>>>> 
>>>> QVector<QVector3D>& Skybox::getCoefficient() const: This function is used to get spherical harmonic (SH) lighting coefficients from coefficients list by its current status;
>>>> 
>>>> QVector<QVector3D>& Skybox::getCoefficient(const int index) const: This function is used to get spherical harmonic (SH) lighting coefficients from coefficients list by its index;
>>>> 
>>>> void Skybox::loadNext(): This function is used to load next texture and spherical harmonic lighting coefficients;
>>>> 
>>>> void Skybox::loadPrev(): This function is used to load previous skybox texture and spherical harmonic lighting coefficients;
>>>> 
>>>> void Skybox::rotate(const QQuaternion& r): This function is used to rotate the skybox, which calls Object3D::rotate(const QQuaternion&) for object rotation;
>>>> 
>>>> void Skybox::translate(const QVector3D& t): This function is used to translate the skybox, which calls Object3D::translate(const QVector3D&) for object translation;
>>>> 
>>>> void Skybox::scale(const float& s): This function is used to scale the skybox, which calls Object3D::scale(const float&) for object scaling;
>>>> 
>>>> void Skybox::setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the skybox, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
>>>> 
>>>> void Skybox::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw the skybox, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>
>> OpenGLWidget
>>
>>> [Widget.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/Widget.cpp): implements Widget.h;
>>>
>>>> Widget::Widget(QWidget* parent): This function is a constructor;
>>>> 
>>>> Widget::~Widget(): This function is a destructor;
>>>> 
>>>> void Widget::initShaders(): This function is used to initialize shaders for skybox and objects;
>>>> 
>>>> void Widget::initializeGL(): This function is used to initialize OpenGL state machine, and initialize skybox ,objects as well as timers;
>>>> 
>>>> void Widget::resizeGL(int width, int height): This function is used to deal with resive event;
>>>> 
>>>> void Widget::paintGL(): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw skybox and other objects;
>>>
>>> [WidgetCallback.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/WidgetCallback.cpp): implements all callback functions in Widget.h;
>>>
>>>> void Widget::keyPressEvent(QKeyEvent* event): This function is used to process key events, which is a Qt event function;
>>>> 
>>>> void Widget::mousePressEvent(QMouseEvent* event): This function is used to process mouse events, which is a Qt event function;
>>>> 
>>>> void Widget::mouseMoveEvent(QMouseEvent* event): This function is used to process mouse move events, which is a Qt event function;
>>>> 
>>>> void Widget::wheelEvent(QWheelEvent* event): This function is used to process wheel events, which is a Qt event function;
>>>> 
>>>> void Widget::timerEvent(QTimerEvent* event): This function is used to process timer events, which is a Qt event function;
>>>
>>> [WidgetParameter.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/WidgetParameter.cpp): implements all parameter setting functions in Widget.h;
>>>
>>>> void Widget::setProjectionMatrix(const QMatrix4x4 & projectMatrix): This function is used to set projection matrix for shader programs;
>>>> 
>>>> const QMatrix4x4 & Widget::getProjectionMatrix() const: This function is used to get projection matrix;
>>>> 
>>>> void Widget::setMeshScale(const float meshScale): This function is used to set mesh scale; PS: since the mesh able to be reloaded is only the last object in the object list (QVector<ObjectEngine3D*>), since the function is designed to scale only the last object;
>>>> 
>>>> const float Widget::getMeshScale() const: This function is used to get mesh scale;
>>>> 
>>>> void Widget::setMaterialType(const float materialType): This function is used to set material type for shader programs;
>>>> 
>>>> void Widget::setMaterialType(const QString & materialType): This function is used to set material type for shader programs by its name;
>>>> 
>>>> const float Widget::getMaterialType() const: This function is used to get material type;
>>>> 
>>>> void Widget::setAmbientFactor(const float ambientFactor): This function is used to set ambient factor for shader programs;
>>>> 
>>>> const float Widget::getAmbientFactor() const: This function is used to get ambient factor;
>>>> 
>>>> void Widget::setContrast(const float contrast): This function is used to set contrast for shader programs;
>>>> 
>>>> const float Widget::getContrast() const: This function is used to get contrast;
>>>> 
>>>> void Widget::setBrightness(const float brightness): This function is used to set brightness for shader programs;
>>>> 
>>>> const float Widget::getBrightness() const: This function is used to get brightness;
>>>> 
>>>> void Widget::setRefractRatio(const float refractRatio): This function is used to set refraction ratio for shader programs;
>>>> 
>>>> const float Widget::getRefractRatio() const: This function is used to get refraction ratio;
>>>> 
>>>> void Widget::reloadMesh(const QString & filePath): This function is used to reload the mesh by its filePath path;
>>>
>>
>> QtFrameWork
>>
>>> [QtInitialization.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/QtInitialization.cpp): implements all Qt initialization functions in SphericalHarmonicsLighting.h;
>>>
>>>> void SphericalHarmonicsLighting::QWidgetInit(): This function is used to initialize all the Qt widgets and build up connections;
>>>> 
>>>> void SphericalHarmonicsLighting::InitHoriSliderAmbientFactor(): This function is used to initialize the Horizontal Slider for Ambient Factor;
>>>> 
>>>> void SphericalHarmonicsLighting::InitHoriSliderContrast(): This function is used to initialize the Horizontal Slider for Contrast;
>>>> 
>>>> void SphericalHarmonicsLighting::InitHoriSliderBrightness(): This function is used to initialize the Horizontal Slider for Brightness;
>>>> 
>>>> void SphericalHarmonicsLighting::InitHoriSliderMeshScale(): This function is used to initialize the Horizontal Slider for Mesh Scale;
>>>> 
>>>> void SphericalHarmonicsLighting::InitHoriSliderRefreactRatio(): This function is used to initialize the Horizontal Slider for Refreaction Ratio;
>>>> 
>>>> void SphericalHarmonicsLighting::InitComboBoxMaterialType(): This function is used to initialize the Combo Box for Material Type;
>>>> 
>>>> void SphericalHarmonicsLighting::InitPushButtonLoadMesh(): This function is used to initialize the Push Button for mesh loading;
>>>> 
>>>> void SphericalHarmonicsLighting::InitConnection(): This function is used to initialize connections between Qt slots and Qt signals;
>>>
>>> [QtSlotFunction.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/QtSlotFunction.cpp): implements all Qt Slot functions in SphericalHarmonicsLighting.h;
>>>
>>>> void SphericalHarmonicsLighting::HorizontalSliderAmbientFactor(int value): This function is used to set ambient factor for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::HorizontalSliderContrast(int value): This function is used to set contrast for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::HorizontalSliderBrightness(int value): This function is used to set brightness for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::HorizontalSliderMeshScale(int value): This function is used to set mesh scale for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::HorizontalSliderRefractRatio(int value): This function is used to set refraction ratio for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::ComboBoxMaterialType(QString value): This function is used to set material type for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>> 
>>>> void SphericalHarmonicsLighting::PushButtonLoadMesh(): This function is used to load mesh for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
>>>
>>> [SphericalHarmonicsLighting.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/SphericalHarmonicsLighting.cpp): implements SphericalHarmonicsLighting.h;
>>>
>>>> SphericalHarmonicsLighting::SphericalHarmonicsLighting(QWidget *parent): This function is a constructor, which is the starting point of the entire project;
>>>
>>
>> Spherical Harmonics
>>
>>> [SphericalHarmonicsEvaluation.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/SphericalHarmonicsEvaluation.cpp): implements all spherical harmonic lighting coefficients evaluation in SphericalHarmonicsSampler.h;
>>>
>>>> QVector<float> SphericalHarmonicsSampler::BasisCoefficient(QVector3D & verCoord): This function is used to generate spherical harmonic lighting basis, a 16x1 vector, for a given point;
>>>> 
>>>> QVector<QVector3D> SphericalHarmonicsSampler::Evaluate(): This function is used to evaluate all the samples and generate spherical harmonics lighting coefficients;
>>>
>>> [SphericalHarmonicsSampler.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/SphericalHarmonicsSampler.cpp): implements SphericalHarmonicsSampler.cpp;
>>>
>>>> SphericalHarmonicsSampler::SphericalHarmonicsSampler(QMap<QString, QImage*> &images): This function is a constructor;
>>>> 
>>>> SphericalHarmonicsSampler::~SphericalHarmonicsSampler(): This function is a destructor;
>>>> 
>>>> void SphericalHarmonicsSampler::setSphericalHarmonicLevel(const int level): This function is used to set spherical harmonics level for the sampler;
>>>> 
>>>> const QVector<Sample*>& SphericalHarmonicsSampler::getSamples() const: This function is used for getting samples for Spherical Harmonics Evaluator;
>>>> 
>>>> QPair<QString, QVector2D> SphericalHarmonicsSampler::CubeXYZ2UV(QVector3D &verCoord): This function is used for the transformation from 3D coordination to uv map coordination;
>>>> 
>>>> float SphericalHarmonicsSampler::NormalRandom(const float mu, const float sigma): This function is used to generate a normal random value;
>>>> 
>>>> void SphericalHarmonicsSampler::RandomSampling(int number): This function is used to generate a given number of samples that consist of coordinations and its corresponding colors on uv map;
>>>
>>
>> [main.cpp](https://github.com/jingyangcarl/SphericalHarmonicsLighting/blob/master/SphericalHarmonicsLighting/main.cpp): main function;
>

## Solution Hierarchy:
![Solution Hierarchy](https://github.com/jingyangcarl/Resources/blob/master/SphericalHarmonicsLighting/Solution_Hierarchy.jpg)
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