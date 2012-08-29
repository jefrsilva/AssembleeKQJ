#include "MainMenuState.h"
#include "Menu.h"
#include "Font.h"

#include "Engine.h"

MainMenuState::MainMenuState() {
    started = false;
    loadedResources = false;

    this->menu = new Menu();
}

MainMenuState::~MainMenuState() {
    if (this->menu) {
        delete this->menu;
        this->menu = 0;
    }
}

void MainMenuState::start() {
    startNewGame = false;
    quitGame = false;

    if (!loadedResources) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->loadMusic("Resources/Music/TEM - Depths.mp3", "Prison");
        audioSystem->loadMusic("Resources/Music/brightforest.mp3", "Forest");
        audioSystem->loadMusic("Resources/Music/Horror09.mp3", "DarkPassageway");
        audioSystem->loadMusic("Resources/Music/Craig Stern - The Sorcerer's Tower.mp3", "Tower");
        audioSystem->loadMusic("Resources/Music/evilfunny.mp3", "HedgeMaze");

        audioSystem->loadSound("Resources/Sounds/select3.wav", "Select");
        audioSystem->setSoundVolume("Select", 64);
        audioSystem->loadSound("Resources/Sounds/explode2.wav", "NormalSlash");
        audioSystem->setSoundVolume("NormalSlash", 64);
        audioSystem->loadSound("Resources/Sounds/missile launch8.wav", "FireSlash");
        audioSystem->setSoundVolume("FireSlash", 64);
        audioSystem->loadSound("Resources/Sounds/birds6.wav", "IceSlash");
        audioSystem->setSoundVolume("IceSlash", 48);
        audioSystem->loadSound("Resources/Sounds/shoot10.wav", "IceBreak");
        audioSystem->setSoundVolume("IceBreak", 48);
        audioSystem->loadSound("Resources/Sounds/slap9.wav", "Shock");
        audioSystem->setSoundVolume("Shock", 64);
        audioSystem->loadSound("Resources/Sounds/hiss1.wav", "Acid");
        audioSystem->setSoundVolume("Acid", 64);
        audioSystem->loadSound("Resources/Sounds/dead4.wav", "Death");
        audioSystem->setSoundVolume("Death", 64);
        audioSystem->loadSound("Resources/Sounds/jump11.wav", "AttackName");
        audioSystem->setSoundVolume("AttackName", 96);
        audioSystem->loadSound("Resources/Sounds/shoot6.wav", "NormalHit");
        audioSystem->setSoundVolume("NormalHit", 96);
        audioSystem->loadSound("Resources/Sounds/Explosion 6-0.wav", "Door");
        audioSystem->setSoundVolume("Door", 96);
        audioSystem->loadSound("Resources/Sounds/Explosion 19-0.wav", "DoorClose");
        audioSystem->setSoundVolume("DoorClose", 96);
        audioSystem->loadSound("Resources/Sounds/slap4.wav", "PlateMoving");
        audioSystem->setSoundVolume("PlateMoving", 64);
        audioSystem->loadSound("Resources/Sounds/hit10.wav", "PlateActivate");
        audioSystem->setSoundVolume("PlateActivate", 64);
        audioSystem->loadSound("Resources/Sounds/dead2.wav", "Stairs");
        audioSystem->setSoundVolume("Stairs", 96);
        audioSystem->loadSound("Resources/Sounds/Explosion 77-3.wav", "PlayerTurn");
        audioSystem->setSoundVolume("PlayerTurn", 64);
        audioSystem->loadSound("Resources/Sounds/Explosion 12-3.wav", "EnemyTurn");
        audioSystem->setSoundVolume("EnemyTurn", 32);
        audioSystem->loadSound("Resources/Sounds/Hit 32-3.wav", "Dialogue");
        audioSystem->setSoundVolume("Dialogue", 32);
        audioSystem->loadSound("Resources/Sounds/Hit 42-2.wav", "Denied");
        audioSystem->setSoundVolume("Denied", 64);
        audioSystem->loadSound("Resources/Sounds/Hit 60-0.wav", "Unlock");
        audioSystem->setSoundVolume("Denied", 64);

        audioSystem->loadSound("Resources/Sounds/creature2.wav", "PuzzleFail");
        audioSystem->setSoundVolume("PuzzleFail", 128);
        audioSystem->loadSound("Resources/Sounds/select12.wav", "PuzzleStep");
        audioSystem->setSoundVolume("PuzzleStep", 128);
        audioSystem->loadSound("Resources/Sounds/spaceship5.wav", "PuzzleSuccess");
        audioSystem->setSoundVolume("PuzzleSuccess", 128);
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double width = videoSystem->getWindowWidth();
    double height = videoSystem->getWindowHeight();

    gluPerspective(45.0f, (double)width / (double)height,
                   3.0 * TILE_SIZE / 4.0, 200.0f);

    gluLookAt(0.0, HALF_TILE, TILE_SIZE,
              0.0, HALF_TILE, -TILE_SIZE,
              0.0, 1.0, 0.0);

    if (!loadedResources) {
        buildModels();
        loadTextures();
    }

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    menu->setFadeColor(Vector(0.0, 0.0, 0.0));
    menu->setFadeAlpha(1.0);
    menu->fadeIn(1500);

    started = true;
    loadedResources = true;
}

void MainMenuState::stop() {
    startNewGame = false;
    quitGame = false;
    started = false;
}

void MainMenuState::update(double dt) {
    menu->update(dt);

    Engine::StateManager *stateManager =
        Engine::Core::getInstance()->getStateManager();
    if (startNewGame && menu->finishedFading()) {
        stateManager->setCurrentState(1);
    } else if (quitGame && menu->finishedFading()) {
        stateManager->setCurrentState(-1);
    }
}

void MainMenuState::render(double edt) {
    menu->render(edt);
}

void MainMenuState::handleKeyboardEvents(SDL_Event* event) {
    if (event->key.type == SDL_KEYDOWN) {

    } else if (event->key.type == SDL_KEYUP) {

    }
}

void MainMenuState::handleMouseEvents(SDL_Event* event) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double winWidth = videoSystem->getWindowWidth();
    double winHeight = videoSystem->getWindowHeight();

    double orthoHeight = 1.0;
    double orthoWidth = (winWidth / winHeight) * orthoHeight;

    if (event->type == SDL_MOUSEBUTTONDOWN) {
        double mouseX =
            ((event->button.x / winWidth) * orthoWidth) - orthoWidth / 2.0;
        double mouseY =
            -(((event->button.y / winHeight) * orthoHeight) - orthoHeight / 2.0);

        unsigned int button = event->button.button;
        if (button == SDL_BUTTON_LEFT) {
            if (!startNewGame && !quitGame && menu->finishedFading()) {
                if (menu->getSelected() == 1) {
                    startNewGame = true;
                } else if (menu->getSelected() == 2) {
                    quitGame = true;
                }
                menu->setFadeColor(Vector(0.0, 0.0, 0.0));
                menu->fadeOut(1500);
            }
        } else if (button == SDL_BUTTON_RIGHT) {

        }
    } else if (event->type == SDL_MOUSEMOTION) {
        double mouseX =
            ((event->motion.x / winWidth) * orthoWidth) - orthoWidth / 2.0;
        double mouseY =
            -(((event->motion.y / winHeight) * orthoHeight) - orthoHeight / 2.0);

        menu->setCursorPosition(Vector(mouseX, mouseY));
    }
}

void MainMenuState::buildModels() {
    Font *font = new Font();
    font->buildDisplayLists();
    delete font;
}

void MainMenuState::loadTextures() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    videoSystem->loadTexture("Resources/Textures/dungeons.png", "Dungeons");
    videoSystem->loadTexture("Resources/Textures/map.png", "Map");
    videoSystem->loadTexture("Resources/Textures/font.png", "Font");
    videoSystem->loadTexture("Resources/Textures/interface.png", "Interface");
    videoSystem->loadTexture("Resources/Textures/items.png", "Items");
    videoSystem->loadTexture("Resources/Textures/monsters.png", "Monsters");
    videoSystem->loadTexture("Resources/Textures/particles.png", "Particles");
    videoSystem->loadTexture("Resources/Textures/title.png", "Title");
}
