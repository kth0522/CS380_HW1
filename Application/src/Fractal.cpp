#include <Fractal.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

/*
 * Implement Fractal class to generate Koch snowflakes mesh (generate snowflake mesh using triangle list).
 * Koch snowflake: https://en.wikipedia.org/wiki/Koch_snowflake
 */

Fractal::Fractal()
{
	//add initial triangle to Fractal's triangle list.
	glm::vec3 a = glm::vec3(-0.5f, 0.0f, 3.0f);
	glm::vec3 c = glm::vec3(0.0f, sqrt(0.75), 3.0f);
	glm::vec3 b = glm::vec3(0.5f, 0.0f, 3.0f);
	 
	Triangle initial_triangle = Triangle(a, b, c);
	triangle_list.append(initial_triangle);
}

Fractal::~Fractal()
{

}

/*
 * TODO: Implement koch snowflake mesh generator
 */

//calculate vector norm
float vector_len(glm::vec3 v) {
	float x = v.x;
	float y = v.y;
	float z = v.z;

	return sqrt(x*x + y*y + z*z);
}

void Fractal::koch_line(glm::vec3 a, glm::vec3 b, int iter)
{
	glm::vec3  b2a = b - a; //vector that points a to b
	glm::vec3 a1 = a + b2a / 3.0f; //first point of fractal's side
	
	float a1_len = vector_len(a1); //norm of a1
	glm::vec3 rot_axis = glm::vec3(a1.x, a1.y, a1_len * sqrt(3)); //to calculate rotation axis that parallel to z-axis and passing point a1
	
	glm::vec3 rot = glm::rotate(b2a, glm::radians(30.0f), rot_axis); //rotate the vector b2a to one point of new triangle
	
	std::vector<glm::vec3> points = std::vector<glm::vec3>(); //create set of points
	
	
	glm::vec3 c = a + rot * sqrt(3.0f) / 3.0f; //second point of fractal's side
	glm::vec3 b1 = a + b2a * 2.0f / 3.0f; //third point of fractal's side

	Triangle new_triangle = Triangle(a1, b1, c); //create new triangle and add it into triangle list
	triangle_list.append(new_triangle);

	points.push_back(a1);
	points.push_back(c);
	points.push_back(b1);

	for (size_t i = 0; i < points.size(); i++) {
		g_vertex_buffer_data.push_back(points[i]);
	}

	//do the koch_line recursively in 5 times
	if (iter < 5){
		koch_line(a, points[0], iter + 1);
		koch_line(points[0], points[1], iter + 1);
		koch_line(points[1], points[2], iter + 1);
		koch_line(points[2], b, iter + 1);
	}
	points.clear();
}
void Fractal::GenerateSnowflake(Engine::Mesh* mesh)
{

	//layout 0: vec4 pos := (x,y,z,w)
	mesh->AddAttribute(4);
	//layout 1: vec4 color := (r,g,b,a)
	mesh->AddAttribute(4);

	std::vector<glm::vec3> initial_triangle = std::vector<glm::vec3>();

	initial_triangle.push_back(glm::vec3(-0.5f, 0.0f, 3.0f));
	initial_triangle.push_back(glm::vec3(0.0f, sqrt(0.75), 3.0f));
	initial_triangle.push_back(glm::vec3(0.5f, 0.0f, 3.0f));
	
	g_vertex_buffer_data = std::vector<glm::vec3>();

	for (size_t i = 0; i < initial_triangle.size(); i++) {
		g_vertex_buffer_data.push_back(initial_triangle[i]);
	}

	//do the koch_line function on the three side of initial trinangle
	koch_line(g_vertex_buffer_data[0], g_vertex_buffer_data[1], 0);
	koch_line(g_vertex_buffer_data[1], g_vertex_buffer_data[2], 0);
	koch_line(g_vertex_buffer_data[2], g_vertex_buffer_data[0], 0);

	int num_vertex = g_vertex_buffer_data.size();
	int num_triangle = triangle_list.size();
	
	for (int i = 0; i < num_triangle; i++) {
		mesh->AddVertexData(triangle_list.list[i].a);
		mesh->AddVertexData(1.5f);
		mesh->AddVertexData(color);

		mesh->AddVertexData(triangle_list.list[i].b);
		mesh->AddVertexData(1.5f);
		mesh->AddVertexData(color);

		mesh->AddVertexData(triangle_list.list[i].c);
		mesh->AddVertexData(1.5f);
		mesh->AddVertexData(color);
		
	}
	
	
	mesh->SetNumElements(num_vertex);
	mesh->CreateMesh();

    return;
}

Triangle::Triangle(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c)
{
	a = _a;
	b = _b;
	c = _c;
}

Triangle_List::Triangle_List()
{
}

void Triangle_List::append(Triangle triangle)
{
	list.push_back(triangle); //add new triangle to the list and increase len
	len += 1;
}

int Triangle_List::size()
{
	return len; //just return the len
}
