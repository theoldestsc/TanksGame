#include "Coordinator.h"
#include <random>
#include <chrono>
#include "System.h"
Coordinator gCoordinator;

struct Vec3
{
	int x, y, z;
	Vec3() = default;
	Vec3(int x, int y, int z):x(x),y(y),z(z){}
	Vec3 operator*(const float value)
	{
		x*=value;
		y*=value;
		z*=value;
		return *this;
	}
	
	Vec3 operator+=(const Vec3& value)
	{
		x+=value.x;
		y+=value.y;
		z+=value.z;
		return *this;
	}

	Vec3 operator+=(const float value)
	{
		x+=value;
		y+=value;
		z+=value;
		return *this;
	}
};

struct Gravity
{
	Gravity() = default;
	Vec3 force;
};

struct RigidBody
{
	RigidBody() = default;
	Vec3 velocity;
	Vec3 acceleration;
};

struct Transform
{
	Transform() = default;
	Vec3 position;
	Vec3 rotation;
	Vec3 scale;
};

class PhysicsSystem:public System
{
	public:
		PhysicsSystem():System(){};
		~PhysicsSystem(){};
		void Update(float dt);
};

void PhysicsSystem::Update(float dt)
{
	for (auto const& entity : mEntities)
	{
		auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto& gravity = gCoordinator.GetComponent<Gravity>(entity);

		transform.position += rigidBody.velocity * dt;

		rigidBody.velocity += gravity.force * dt;
	}
}

int main()
{
	bool quit = false;
	gCoordinator.Init();

	gCoordinator.RegisterComponent<Gravity>();
	gCoordinator.RegisterComponent<RigidBody>();
	gCoordinator.RegisterComponent<Transform>();

	auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();

	Signature signature;
	signature.set(gCoordinator.GetComponentType<Gravity>());
	signature.set(gCoordinator.GetComponentType<RigidBody>());
	signature.set(gCoordinator.GetComponentType<Transform>());
	gCoordinator.SetSystemSignature<PhysicsSystem>(signature);

	std::vector<Entity> entities(MAX_ENTITIES);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	float scale = randScale(generator);

	for (auto& entity : entities)
	{
		entity = gCoordinator.CreateEntity();

		gCoordinator.AddComponent(
			entity,
			Gravity{.force = Vec3(0.0f, randGravity(generator), 0.0f)});

		gCoordinator.AddComponent(
			entity,
			RigidBody{
				.velocity = Vec3(0.0f, 0.0f, 0.0f),
				.acceleration = Vec3(0.0f, 0.0f, 0.0f)
			});

		gCoordinator.AddComponent(
			entity,
			Transform{
				.position = Vec3(randPosition(generator), randPosition(generator), randPosition(generator)),
				.rotation = Vec3(randRotation(generator), randRotation(generator), randRotation(generator)),
				.scale = Vec3(scale, scale, scale)
			});
	}

	float dt = 0.0f;

	while (!quit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		physicsSystem->Update(dt);

		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}
}