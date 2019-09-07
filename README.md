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
>>> [Camera3D.h]():
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
>>> [Group3D.h]():
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
>>> [Material.h]():
>>>
>>> [MaterialLibrary.h]():
>>>
>>> [Object3D.h]():
>>>
>>> [ObjectEngine3D.h]():
>>>
>>> [Skybox.h]():
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
>>> [Camera3D.cpp](): implements Camera3D.h
>>>
>>> [Group3D.cpp](): implements Group3D.h
>>>
>>> [Material.cpp](): implements Material.h
>>>
>>> [MaterialLibrary.cpp](): implements MaterialLibrary.h
>>>
>>> [Object3D.cpp](): implements Object3D.h
>>>
>>> [ObjectEngine3D.cpp](): implements ObjectEngine3D.h
>>>
>>> [Skybox.cpp]: implements skybox.h
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





> Form Files
>> [Tutorial1.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Tutorial1.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
>>
>>> void initializeGL(): This function is used to initialize OpenGL state machine, and initialize shaders ,objects and etc.;
>>> 
>>> void resizeGL(int width, int height): This function is used to deal with resive event;
>>>
>>> void paintGL(): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw other objects;
>>>
>>> void initShaders(): This function is used to initialize shaders and objects;
>>>
>>> void initCube(float width): This function is used to load graphics data for a cube, including vertex data and index data;
>>
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/main.cpp)
>>
>> [Tutorial1.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.cpp): implements Tutorial1.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Widget.cpp): implements Widget.h;
>
> Shader Files
>> [FragmentShader.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/FragmentShader.fsh): The fragment shader adds ambient light;
>>
>> [VertexShader.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/VertexShader.vsh): The vertex shader projects vertices;
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