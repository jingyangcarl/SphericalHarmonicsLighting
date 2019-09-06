Spherical Harmonic Lighting
=============================

# Spherical Harmonic Lighting Result
![Tutorial 1](https://github.com/jingyangcarl/Resources/blob/master/QtOpenGLTutorials/Tutorial1/result.jpg)

# Solution Introduction
This tutorial solution is used to build up an template for using OpenGL with Qt, and display a simple cube with texture;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.13.0

# Solution Documentation:
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
>
> Source Files
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