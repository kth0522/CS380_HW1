#include <Snowflake.hpp>
#include <Fractal.hpp>
#include <PerVertexColorMaterial.hpp>
/*
 * TODO: Inherit RenderObject class to implement animation
 */
Snowflake::Snowflake(Engine::Mesh* mesh, Engine::Material* material) : Engine::RenderObject(mesh, material)
{
	Fractal fractal = Fractal();
	
	fractal.GenerateSnowflake(mesh);
	Engine::RenderObject* snowflake = new Engine::RenderObject(mesh, material);
	snowflake->SetPosition(glm::vec3(-5.0f + 10.0f*((rand() % 255) / 255.0f), 5.0f*((rand() % 255) / 255.0f), 0.0f)); // randomize the initial snowflake position 
	snowflake->SetScale(glm::vec3(0.2f, 0.2f, 0.2f));
}

// Add more functions