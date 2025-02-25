#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node *nodePTR)
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	img = App->tex->Load("textures/test.png");
	App->audio->PlayMusic("audio/music/music_sadpiano.ogg");
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	App->render->Blit(img, 0, 0);
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKeyDown(SDLK_ESCAPE) == true)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
