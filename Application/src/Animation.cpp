#include <Animation.hpp>

Animation::Animation()
{
    _snowflakes = std::vector<Snowflake*>();
}

Animation::~Animation()
{
    _snowflakes.clear();
}

void Animation::AddSnowflake(Snowflake* snowflake)
{
    _snowflakes.push_back(snowflake);
}

void Animation::Animate(Engine::Camera* cam, float deltaTime)
{
	for (int i = 0; i < _snowflakes.size(); i++) {
		_snowflakes[i]->SetOrientation(glm::rotate(_snowflakes[i]->GetOrientation(), glm::radians(deltaTime*10.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
		_snowflakes[i]->SetPosition(_snowflakes[i]->GetPosition() + glm::vec3(0.0, deltaTime*-0.1f, 0.0));
		_snowflakes[i]->Render(cam);

		//if snowflake go out of the window then reset the position to the inside of the window
		if (_snowflakes[i]->GetPosition().y < -5.0f) {
			_snowflakes[i]->SetPosition(glm::vec3(-5.0f + 10.0f * ((rand() % 255) / 255.0f), 5.0f * ((rand() % 255) / 255.0f), 0.0f));
		}
	}
	
}