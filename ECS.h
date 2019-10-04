#pragma once

#include <iostream>
#include <vector>
#include<memory>
#include<algorithm>
#include<bitset>
#include<array>


class Component;
class Entity;

using ComponentID = std::size_t;
//this function will be put in place where we want is where we use it
inline ComponentID getComponentTypeID()
{
	//example ID 1 will be physics, 2 will be position will always have same ID
	static ComponentID lastID = 0;
	return lastID++;
}
//makes sense to get the TYpe of ID rather than a specific component ID
template <typename T> inline componentID getComponentTypeID() noexcept
{
	//this will generate a new last ID for us and put in our typeID 
	static ComponentID typeID = getComponentTypeID();
	return typeID();

}


constexpr std::size_t maxComponents = 32;


//With this Comp bitset if we need to ind if an entity has a selection of components we can compare generate a bitset then we know we
//have componets
//The array is the length of our max components
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::_Array_iterator<Component*, maxComponents>;
// we need a base class of components

class Component
{
public:

	//has a reference to its owner
	Entity* entity;
//some virtual functions that we can overwrite

// the virtual init means we can call other functions
	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}

};


class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	//this vector will hold a list of the components

	//this is the component array

	ComponentArray componentArray;


	ComponentBitset componentBitSet;
	// we will access these using functions
public:
	void update()
	{

//have the entity loop through all the components to be drawn. We loop through the components list defined in the vector array
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();

	}

	void draw() {}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	//destroy - how it works. 
	//on any given component because our component has a ref to the owner we can call the 
	//entities destroy function from one of our components
	//then in the manager class when it loops through to see if our entities are active or not
	//then it will remove them from the game

	//we want our entity class to be able to see if it has components

	//this is where the BitSet comes into play


	template<typename T> bool hasComponent() const
	{

		return componentBitSet[getComponentID<T>()]

	}

	template<typename T, typename... TArgs>
	//we will return the address of T so it can be added to the array
	T& addComponent(TArgs&&... mARgs)
	{

		T* c(newT(std::forward<TArgs>(mARgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));
		//type index = to c
		//when we add a position component it will always be in the same position, physics in the correct array etc
		componentArray[getComponentTypeID<T>()]; = c;
		componentBitSet[getComponentTypeID<T>()]; = true;

		//once we've added our component to the vector and the component array to check if we have it
		//and the bitset to show it
		//We can now call init of the comonent and get references to other components if we need them

		c->init();
		return *c;

		//the use of pointers to generate the correct 'code' form the trype of component we looking for

	}
		template<typename T> T& getComponent() const
		{
			//use of auto to generate the component typeID
			auto ptr(componentArray[getComponentTypeID]<T>()]);

			//a static casting to all across the program
			return *static_cast<T*>(ptr);


		}


		class Manager
		{
			//use a smart pointer
		private:
			std::vector<std::unique_ptr<Entity>> entities;

		public:
			void update()
			{
				for (auto& e : entities) e->update();
			}

			void draw()
			{
				for (auto& e : entities) e->draw();
			}

			void refresh() 
			
			{
				entities.erase(std::remove_if(std::begin(entities), std::end(entities),
					[](const std::unique_ptr<Entity> &mEntity)
				{
					return !mEntity->isActive();

				}),
					std::end(entities)); //this will remove entities if not active
			}

			Entity& addEntity()
			{
				Entity* e = new Entity();
				std::unique_ptr<Entity>uPtr{ e }; //initialising uPtr to e
				entities.emplace_back(std::move(uPtr));
				return *e;
			}
};