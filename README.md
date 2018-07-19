# GameEngine is a simple 2.5D game engine based on sprites.
## Introduction
### The project goal and structure
The idea behind this project was and is to recreate a game engine similar to id tech 0 or the engines used by DOOM and DOOM 2. This engine is designed to be very fast, allow experienced users to take control over for optimisations and even take over certain parts. You may see code repetition and that is because most of the times it is faster that way.
Curently the project is split into 4 parts:
1. GameEngine - The main part.
2. Renderer - The rendering part.
3. Scaler - Image manipulation utils.
4. Tests - Various c++ executable test files to showcase functions

### Building
First clone the github repository:

$ git clone https://github.com/Vladithur/GameEngine.git

Then open the /path/to/GameEngine/GameEngine/GameEngine.sln file in Visual Studio

Rebuild all projects, you might need to change some setting for each project in properties

### Troubleshooting

Depending on your windows sdk version, you might need to change it. By default this project uses Windows 10 Sdk version 10.0.16299.0

(Screenshot for Tests projects) ![image](https://user-images.githubusercontent.com/29858044/42924226-d96a9e3a-8b31-11e8-8670-3b8262c2aa52.png)
