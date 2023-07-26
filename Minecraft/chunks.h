#pragma once

#include "engine.h"

stv::Vector3 prespective;

void stv::matrix3d::updateOrder(int chunkid, Vector3 playerPosition) {
	std::vector<stv::Vector3> chunk{};
	std::vector<float> distances{};

	for (int i = 0; i < 16; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 16; k++) if (gme::chunks[chunkid].data[i][j][k] == 1) {
		chunk.push_back(Vector3(i, j, k));
		distances.push_back((float)(abs(sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2)) - sqrt(pow(playerPosition.x, 2) + pow(playerPosition.y, 2) + pow(playerPosition.z, 2)))));
	}

	for (stv::Vector3 x : chunk) {
		for (int i = 0; i < chunk.size() - 1; i++) {
			if (distances[i] > distances[i + 1]) {
				stv::Vector3 temp = chunk[i];
				chunk[i] = chunk[i + 1];
				chunk[i + 1] = temp;
				float tempd = distances[i];
				distances[i] = distances[i + 1];
				distances[i + 1] = tempd;
			}
		}
	}

	gme::chunks[chunkid].renderOrder = chunk;
}

std::vector<stv::Vector3> getOrder(int chunkid) {
	return gme::chunks[chunkid].renderOrder;
}

namespace gme {
	void createChunk(stv::Vector3 position = stv::Vector3(0,0,0)) {
		stv::matrix3d chunk(16, 16, 16);

		for (int i = 0; i < 15; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 16; k++)
			chunk.data[i][j][k] = 1;

		chunks.push_back(chunk);
	}

	void loadChunk(int chunkid = 0) {
		int size = 50;
		std::vector<stv::Vector3> chunk = getOrder(chunkid);

		for (const stv::Vector3& blockPos : chunk)
			geo::cube(stv::Vector3(blockPos.z * size, blockPos.y * size, blockPos.x * size)-7.5*50, stv::Vector3(size, size, size), prespective);
		
	}

}