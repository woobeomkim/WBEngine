#pragma once
#include "commonInclude.h"
#include "WBEntity.h"
#include "WBGameObject.h"

namespace WB
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		 virtual void Initialize();
		 virtual void Update();
		 virtual void LateUpdate();
		 virtual void Render(HDC hdc);

		 void AddGameObject(GameObject* gameObject);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}

