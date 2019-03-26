// STL
#include <iostream>

// include opengl extension and application library
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


// include Engine
#include <Camera.hpp>
#include <Mesh.hpp>
#include <Material.hpp>
#include <RenderObject.hpp>

// include application headers
#include <Fractal.hpp>
#include <DefaultMaterial.hpp>
#include <PerVertexColorMaterial.hpp>
#include <Snowflake.hpp>
#include <Animation.hpp>



// TODO: Implement gradient rectangle mesh generator for background
//I use two triangle to draw rectangle.
void GenerateGradientRectangle(Engine::Mesh* mesh)
{
	//layout 0: vec4 pos := (x,y,z,w)
	mesh->AddAttribute(4);
	//layout 1: vec4 color := (r,g,b,a)
	mesh->AddAttribute(4);

	glm::vec3 position_data[] = {
		glm::vec3(-100.0f, -100.0f, -10.0f),
		glm::vec3(100.0f, -100.0f, -10.0f),
		glm::vec3(-100.0f, 100.0f, -10.0f),
		glm::vec3(100.0f, 100.0f, -10.0f)

	};

	glm::vec3 color_data[] = {
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)

	};



	for (int i = 0; i < 4; i++) {
		mesh->AddVertexData(position_data[i]);
		mesh->AddVertexData(7.0f);
		mesh->AddVertexData(color_data[i]);
		mesh->AddVertexData(1.0f);                              

	}
	mesh->SetDrawMode(GL_TRIANGLE_STRIP); 
	mesh->SetNumElements(4);
	mesh->CreateMesh();

	return;
}

// TODO: Implement custom type mesh generator for background object
// I designed a yellow moon.
void GenerateBackgroundMeshType1(Engine::Mesh* mesh)
{
	//layout 0: vec4 pos := (x,y,z,w)
	mesh->AddAttribute(4);
	//layout 1: vec4 color := (r,g,b,a)
	mesh->AddAttribute(4);

	glm::vec3 position_data[] = {
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, sqrt(2)*1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, sqrt(2)*1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-sqrt(2)*1.0f, 0.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-sqrt(2)*1.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f,1.0f),
		glm::vec3(0.0f, -sqrt(2)*1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, -sqrt(2)*1.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f)

	};
	
	for (int i = 0; i < 18; i++) {
		mesh->AddVertexData(position_data[i]);
		mesh->AddVertexData(1.0f);
		mesh->AddVertexData(glm::vec3(0.95f, 1.0f, 0.0f)); //color vector of yellow
		mesh->AddVertexData(1.0f);

	}

	//mesh->SetDrawMode(GL_TRIANGLE_FAN);
	mesh->SetNumElements(18);
	mesh->CreateMesh();

    return;
}

// TODO: Implement custom type mesh generator for background object
// I designed a red sun.
void GenerateBackgroundMeshType2(Engine::Mesh* mesh)
{
	//layout 0: vec4 pos := (x,y,z,w)
	mesh->AddAttribute(4);
	//layout 1: vec4 color := (r,g,b,a)
	mesh->AddAttribute(4);

	glm::vec3 position_data[] = {
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(sqrt(2)*1.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, sqrt(2)*1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, sqrt(2)*1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-sqrt(2)*1.0f, 0.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-sqrt(2)*1.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f,1.0f),
		glm::vec3(0.0f, -sqrt(2)*1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, -sqrt(2)*1.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),

		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(sqrt(2)*1.0f, 0.0f, 1.0f)

	};
	
	for (int i = 0; i < 24; i++) {
		mesh->AddVertexData(position_data[i]);
		mesh->AddVertexData(1.0f);
		mesh->AddVertexData(glm::vec3(0.9776f, 0.2274f, 0.0823f)); //color vector of sun
		mesh->AddVertexData(1.0f);

	}

	mesh->SetNumElements(24);
	mesh->CreateMesh();

    return;
}

int main(int argc, char** argv)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    GLFWwindow* window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Homework 1 - Snowflake Animation (20150227)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        std::cout << "GLEW Error: " << glewGetErrorString(glewError) << std::endl;
        exit(1);
    }

    
    Animation* animation = new Animation();

    Engine::Camera* mainCamera = new Engine::Camera();
	PerVertexColorMaterial* material = new PerVertexColorMaterial();
	material->CreateMaterial();

	//create moon instance
	Engine::Mesh* custom1_mesh = new Engine::Mesh();
	GenerateBackgroundMeshType1(custom1_mesh);
	Engine::RenderObject custom1Render = Engine::RenderObject(custom1_mesh, material);
	
	custom1Render.SetPosition(glm::vec3(-3.0f, 2.0f, 0.0f));
	custom1Render.SetScale(glm::vec3(0.5f, 0.5f, 0.5f));

	//create sun instance
	Engine::Mesh* custom2_mesh = new Engine::Mesh();
	GenerateBackgroundMeshType2(custom2_mesh);
	Engine::RenderObject custom2Render = Engine::RenderObject(custom2_mesh, material);

	custom2Render.SetPosition(glm::vec3(3.0f, 2.0f, 0.0f));
	custom2Render.SetScale(glm::vec3(0.5f, 0.5f, 0.5f));

	//create background
	Engine::Mesh* background_mesh = new Engine::Mesh();
	GenerateGradientRectangle(background_mesh);
	Engine::RenderObject backGroundRender = Engine::RenderObject(background_mesh, material);

    // Create snowflake instances
	Engine::Mesh* mesh1 = new Engine::Mesh();
	Snowflake exampleSnowflake = Snowflake(mesh1, material);

	animation->AddSnowflake(&exampleSnowflake);

		
	Engine::Mesh* mesh2 = new Engine::Mesh();
	Snowflake exampleSnowflake2 = Snowflake(mesh2, material);
	animation->AddSnowflake(&exampleSnowflake2);
		
	Engine::Mesh* mesh3 = new Engine::Mesh();
	Snowflake exampleSnowflake3 = Snowflake(mesh3, material);
	animation->AddSnowflake(&exampleSnowflake3);

	Engine::Mesh* mesh4 = new Engine::Mesh();
	Snowflake exampleSnowflake4 = Snowflake(mesh4, material);
	animation->AddSnowflake(&exampleSnowflake4);

	Engine::Mesh* mesh5 = new Engine::Mesh();
	Snowflake exampleSnowflake5 = Snowflake(mesh5, material);
	animation->AddSnowflake(&exampleSnowflake5);

	Engine::Mesh* mesh6 = new Engine::Mesh();
	Snowflake exampleSnowflake6 = Snowflake(mesh6, material);
	animation->AddSnowflake(&exampleSnowflake6);


	Engine::Mesh* mesh7 = new Engine::Mesh();
	Snowflake exampleSnowflake7 = Snowflake(mesh7, material);
	animation->AddSnowflake(&exampleSnowflake7);

	Engine::Mesh* mesh8 = new Engine::Mesh();
	Snowflake exampleSnowflake8 = Snowflake(mesh8, material);
	animation->AddSnowflake(&exampleSnowflake8);

	Engine::Mesh* mesh9 = new Engine::Mesh();
	Snowflake exampleSnowflake9 = Snowflake(mesh9, material);
	animation->AddSnowflake(&exampleSnowflake9);

	Engine::Mesh* mesh10 = new Engine::Mesh();
	Snowflake exampleSnowflake10 = Snowflake(mesh10, material);
	animation->AddSnowflake(&exampleSnowflake10);

	
	

   

	//Engine::RenderObject renderObject = Engine::RenderObject(mesh, material);
    mainCamera->SetPosition(glm::vec3(0.0f, 0.0f, 7.5f));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Enable depth test
        glEnable(GL_DEPTH_TEST);

        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK); // Cull back-facing triangles -> draw only front-facing triangles

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Render background and background objects(sun, moon)
		custom1Render.Render(mainCamera);
		custom2Render.Render(mainCamera);
		backGroundRender.Render(mainCamera);

        // Apply constant animation (1.0f is default value. (1.0s) you should change this value for supporting consistent animation)
        animation->Animate(mainCamera, 0.1f);
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
				
        /* Poll for and process events */
        glfwPollEvents();
    }

    delete mainCamera;

    glfwTerminate();
    return 0;

}