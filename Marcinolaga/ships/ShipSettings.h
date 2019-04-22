#pragma once

#include <entity/GraphicComponent.h>

enum ship_layers : GraphicComponent::layer {
	player = 100,
	player_bullet = 200,
	enemy = 50,
	enemy_bullet = 201,
	background = 0,
	ui = 1000,
};

const int player_max_lives = 3;
const float player_respawn_time = 3.0f;

const float player_speed = 300;
const float player_bullet_speed = 1000;
const int collide_player = 1;
const int collide_player_bullet = 2;

const float enemy_speed = 30;
const float enemy_bullet_speed = 250;
const int collide_enemy = 2;
const int collide_enemy_bullet = 3;

const int level_up_per_seconds = 5;