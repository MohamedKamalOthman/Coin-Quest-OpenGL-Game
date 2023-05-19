#pragma once

#include "../ecs/world.hpp"
#include "../components/mesh-renderer.hpp"
#include "../components/movement.hpp"
#include "../components/free-camera-controller.hpp"
#include "../components/camera.hpp"
#include "../components/player.hpp"
#include "../components/score-digit.hpp"
#include "../components/tags/heart.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <imgui_impl/imgui_impl_opengl3.h>

namespace our
{

    class HUDSystem
    {
    public:
        // This should be called every frame to update the HUD(Heads Up Display)
        void update(World *world, float deltaTime)
        {
            PlayerComponent *player = nullptr;
            // For each entity in the world get the player position
            for (auto entity : world->getEntities())
            {
                // Get player component
                player = entity->getComponent<PlayerComponent>();
                if (player)
                {
                    break;
                }
            }

            if (!player)
            {
                return;
            }

            // Draw hud on screen
            ImGui::GetFont()->Scale = 4.0f;
            ImGui::PushFont(ImGui::GetFont());
            ImDrawList *drawList = ImGui::GetBackgroundDrawList();
            drawList->AddText(ImVec2(25, 25), ImColor(1.0f, 1.0f, 0.0f), std::to_string(player->score).c_str());
            drawList->AddText(ImVec2(1230, 25), ImColor(1.0f, 1.0f, 0.0f), std::to_string(player->lives).c_str());
            ImGui::PopFont();
        }
    };

}
