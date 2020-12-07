/*
License (OLC-3)
Copyright 2018, 2019, 2020 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions or derivations of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions or derivative works in binary form must reproduce the above copyright notice. This list of conditions and the following disclaimer must be reproduced in the documentation and/or other materials provided with the distribution.

Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <iostream>
using namespace std;
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

int current_score = 0;
int max_score = 0;
int* msp = &max_score;
int* csp = &current_score;

class Christmas : public olc::PixelGameEngine{
public:
	Christmas(){
		sAppName = "Christmas";
	}

private:
	float playerPosition = 0.0f;
	float playerVelocity = 0.0f;
	float playerAcceleration = 0.0f;
	float gravity = 100.0f;
	float levelPosition = 0.0f;
	float obsticleWidth;
	float freeSpace = 20;
	list<int> listObsticles;
	bool pHasCollided = false;
	bool pResetGame = false;


public:
	bool OnUserCreate() override{
		listObsticles = { 0, 0, 0, 0 };
		pResetGame = true;
		obsticleWidth = (float)ScreenWidth() / (float)(listObsticles.size() - 1);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override{
		if (pResetGame){
			pHasCollided = false;
			pResetGame = false;
			listObsticles = { 0, 0, 0, 0 };
			playerAcceleration = 0.0f;
			playerVelocity = 0.0f;
			playerPosition = ScreenHeight() / 2.0f;
			*csp = 0;
		}

		// gra
		if (pHasCollided){
			string c_s = "Score: " + to_string(*csp);
			string m_s = "Highest \nscore: " + to_string(*msp);
			DrawString(1, 1, c_s);
			DrawString(1, 20, m_s);
			// czeka po smierci
			if (GetKey(olc::SPACE).bReleased)
				pResetGame = true;
		}
		else
		{

			if (GetKey(olc::SPACE).bPressed && playerVelocity >= gravity / 10.0f){
				playerAcceleration = 0.0f;
				playerVelocity = -gravity / 4.0f;
				*csp = *csp + 1;
				if (*csp > *msp)
					*msp = *csp;
			}
			else
				playerAcceleration += gravity * fElapsedTime;

			if (playerAcceleration >= gravity) {
				playerAcceleration = gravity;
			}
			playerVelocity += playerAcceleration * fElapsedTime;
			playerPosition += playerVelocity * fElapsedTime;
			levelPosition += 14.0f * fElapsedTime;

			if (levelPosition > obsticleWidth){
				levelPosition -= obsticleWidth;
				listObsticles.pop_front();
				int i = rand() % (ScreenHeight() - 20);
				if (i <= 10) i = 0;
				listObsticles.push_back(i);
			}

			Clear(olc::DARK_BLUE);

			int nBirdX = (int)(ScreenWidth() / 3.0f);

			// Pierwsza detekcja kolizji
			pHasCollided = playerPosition < 2 || playerPosition > ScreenHeight() - 2;

			// Rysowanie choinek i druga detekcja kolizji
			int nSection = 0;
			
			for (auto s : listObsticles){
				if (s != 0){
					float level = s / 3;
					FillRect(nSection * obsticleWidth + 10 - levelPosition + 3, ScreenHeight()-s, obsticleWidth - 15 - 6, ScreenHeight(), olc::GREEN);
					FillRect(nSection * obsticleWidth + 10 - levelPosition + 1, ScreenHeight()-s +level, obsticleWidth - 15 - 2, ScreenHeight(), olc::GREEN);
					FillRect(nSection * obsticleWidth + 10 - levelPosition, ScreenHeight()-s+level*2, obsticleWidth - 15, ScreenHeight(), olc::GREEN);
					level = (ScreenHeight() - s - 15) / 3;
					FillRect(nSection * obsticleWidth + 10 - levelPosition + 3, 0, obsticleWidth - 15 - 6, ScreenHeight() - s - freeSpace, olc::GREEN);
					FillRect(nSection * obsticleWidth + 10 - levelPosition + 1, 0, obsticleWidth - 15 - 2, ScreenHeight() - s - freeSpace - level, olc::GREEN);
					FillRect(nSection * obsticleWidth + 10 - levelPosition, 0, obsticleWidth - 15, ScreenHeight() - s - freeSpace - level * 2, olc::GREEN);

					if ((((nSection * obsticleWidth + 10 - levelPosition + 3 < nBirdX) && (nBirdX < nSection * obsticleWidth + 10 - levelPosition + 3 + obsticleWidth - 15 - 6)) || 
						((nSection * obsticleWidth + 10 - levelPosition + 3 < nBirdX+4) && (nBirdX+4 < nSection * obsticleWidth + 10 - levelPosition + 3 + obsticleWidth - 15 - 6))) &&
						(((0 < playerPosition - 1) && (playerPosition - 1 < ScreenHeight() - s - freeSpace))||((0 < playerPosition + 2) && (playerPosition + 2 <= ScreenHeight() - s - freeSpace)) ||
						(((ScreenHeight()-s < playerPosition - 1)&&(playerPosition-1 < ScreenHeight()))||((ScreenHeight() - s < playerPosition+2)&&(playerPosition+2<ScreenHeight()))))) {
						pHasCollided = true;
					}
				}
				nSection++;
			}

			// rysowanie gracza
			if (playerVelocity > 0){
				DrawLine(nBirdX, playerPosition + 0, nBirdX + 4, playerPosition + 0, olc::RED);
				DrawLine(nBirdX, playerPosition + 1, nBirdX + 4, playerPosition + 1, olc::YELLOW);
				DrawLine(nBirdX, playerPosition + 2, nBirdX + 4, playerPosition + 2, olc::RED);
				DrawLine(nBirdX + 2, playerPosition, nBirdX + 2, playerPosition + 2, olc::YELLOW);
				DrawLine(nBirdX + 2, playerPosition - 2, nBirdX + 2, playerPosition + 0, olc::YELLOW);
			}
			else{
				DrawLine(nBirdX, playerPosition + 0, nBirdX + 4, playerPosition + 0, olc::RED);
				DrawLine(nBirdX, playerPosition + 1, nBirdX + 4, playerPosition + 1, olc::YELLOW);
				DrawLine(nBirdX, playerPosition + 2, nBirdX + 4, playerPosition + 2, olc::RED);
				DrawLine(nBirdX + 2, playerPosition, nBirdX + 2, playerPosition + 2, olc::YELLOW);
				DrawLine(nBirdX + 1, playerPosition - 1, nBirdX + 3, playerPosition - 1, olc::YELLOW);
			}
			
		}

		return true;
	}
};

int main(){
	Christmas game;
	if (game.Construct(80, 48, 16, 16))
		game.Start();
	return 0;
}
