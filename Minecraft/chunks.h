#pragma once

#include "engine.h"

stv::Vector3 prespective;

void stv::matrix3d::updateOrder(int chunkid, Vector3 playerPosition) {
	std::vector<stv::Vector3> chunk;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 16; j++) for (int k = 0; k < 16; k++) if (gme::chunks[chunkid][i][j][k] == 1) {
		chunk.push_back(Vector3(i, j, k));
	}

	for (int i = 0; i < chunk.size()-1; i++) {
		int current_block_distance = pow(chunk[i].x, 2) + pow(chunk[i].y, 2) + pow(chunk[i].z, 2) - pow(playerPosition.x, 2) + pow(playerPosition.y, 2) + pow(playerPosition.z, 2);
		int next_block_distance = pow(chunk[i + 1].x, 2) + pow(chunk[i + 1].y, 2) + pow(chunk[i + 1].z, 2) - pow(playerPosition.x, 2) + pow(playerPosition.y, 2) + pow(playerPosition.z, 2);
		if (current_block_distance > next_block_distance) {
			Vector3 temp = chunk[i];
			chunk[i] = chunk[i + 1];
			chunk[i + 1] = temp;
		}
	}

	gme::chunks[chunkid].renderOrder = chunk;
}

std::vector<stv::Vector3> getOrder(int chunkid) {
	return gme::chunks[chunkid].renderOrder;
}

namespace gme {
	void createChunk(int position = 0) {
		stv::matrix3d chunk(16, 16, 16);

		for (int i = 0; i < 3; i++) for (int j = 0; j < 16; j++) for (int k = 0; k < 16; k++)
			chunk.data[i][j][k] = 1;

		chunks.push_back(chunk);
	}

	void loadChunk(int chunkid = 0) {
		int size = 50;
		std::vector<stv::Vector3> chunk = getOrder(chunkid);

		for (auto blockPos : chunk)
			geo::cube(stv::Vector3(blockPos.z * size, blockPos.y * size, blockPos.x * size), stv::Vector3(size, size, size), prespective);
		
	}

}