#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "functions.h"
#include "Classes.h"
#include <iostream>

using namespace std;


//#undef main

const int SPEED = 5;

extern SDL_Window* Window;
extern SDL_Renderer* Renderer;
extern Mix_Music* Oblivion;
extern LButtonPosition buttons[2];
extern bool b_mainMenu, b_stage0, b_stage1, b_stage2, b_stage3, b_stage4, dia[20], b_stage_akasztas, b_stage_keseles, b_stage_happyending, b_stage_asthma, b_stage_denial;
extern unsigned int meroindex;

int main()
{
	b_mainMenu = true;
	if (init())
	{
		if (loadMedia())
		{

			bool quit = false;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					if (b_mainMenu)
					{
						buttons[0].HandleEvent(&e);
					}
					else if (b_stage0)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (!dia[1])
								changeDialogStage0();
							else
							{
								b_stage0 = false;
								b_stage1 = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage1();
							}
						}
					}
					else if (b_stage1)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (!dia[4]) //ha ez mar true, akkor meg volt az osszes parbeszedresz
								changeDialogStage1();
							else
							{
								if (e.key.keysym.sym == SDLK_y)
								{
									b_stage1 = false;
									b_stage2 = true;
									for (int i = 0; i < 6; ++i)
										dia[i] = false;
									dia[0] = true;
									darkness = 255;
									loadTextsStage2();
								}
								else if (e.key.keysym.sym == SDLK_n)
								{
									b_stage1 = false;
									b_stage_akasztas = true;
									for (int i = 0; i < 6; ++i)
										dia[i] = false;
									dia[0] = true;
									darkness = 255;
									loadTextsStage_akasztas();
								}
							}
						}

					}
					else if (b_stage2)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (!dia[3])
								changeDialogStage2();
							else
							{
								if (e.key.keysym.sym == SDLK_1)
								{
									b_stage2 = false;
									b_stage_keseles = true;
									for (int i = 0; i < 6; ++i)
										dia[i] = false;
									dia[0] = true;
									darkness = 255;
									loadTextsStage_keseles();
								}
								else if (e.key.keysym.sym == SDLK_2)
								{
									b_stage2 = false;
									b_stage3 = true;
									for (int i = 0; i < 6; ++i)
										dia[i] = false;
									dia[0] = true;
									darkness = 255;
									loadTextsStage3();
								}
							}
						}

					}
					else if (b_stage3)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (dia[4])
							{
								b_stage3 = false;
								b_stage_akasztas = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage_akasztas();
							}
							else if (!dia[3])
								changeDialogStage3();
							else if (dia[3])
							{
								if (e.key.keysym.sym == SDLK_1)
								{
									changeDialogStage3();
								}
								else if (e.key.keysym.sym == SDLK_2)
								{
									b_stage3 = false;
									b_stage4 = true;
									for (int i = 0; i < 6; ++i)
										dia[i] = false;
									dia[0] = true;
									darkness = 255;
									loadTextsStage4();
									Mix_HaltMusic();
									Mix_PlayMusic(Cave, -1);
								}
								else if (e.key.keysym.sym == SDLK_3)
								{
									changeDialogStage3();
								}
							}

						}
					}
					else if (b_stage4)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (e.key.keysym.sym == SDLK_e)
							{
								b_stage4 = false;
								b_stage5 = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage5();
							}
						}
					}
					else if (b_stage5)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (e.key.keysym.sym == SDLK_1)
							{
								b_stage5 = false;
								b_stage6 = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage6_1();
							}
							else if (e.key.keysym.sym == SDLK_2)
							{
								b_stage5 = false;
								b_stage_asthma = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage_asthma();
								//halal asthma
							}
							else if (e.key.keysym.sym == SDLK_3)
							{
								b_stage5 = false;
								b_stage6 = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage6_2();
							}
						}
					}
					else if (b_stage6)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (!dia[1])
								changeDialogStage6();
							else
							{
								b_stage6 = false;
								b_stage7 = true;
								for (int i = 0; i < 6; ++i)
									dia[i] = false;
								dia[0] = true;
								darkness = 255;
								loadTextsStage7();
							}
						}
					}
					else if (b_stage7)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							if (!dia[20])
							{
								if (dia[0])
									changeDialogStage7();
								else if (dia[1])
									changeDialogStage7();
								else if (dia[2])
									changeDialogStage7();
								else if (dia[3])
									changeDialogStage7();
								else if (dia[4])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										changeDialogStage7();
										++meroindex;
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										changeDialogStage7();
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										b_stage7 = false;
										b_stage_denial = true;
										for (int i = 0; i < 6; ++i)
											dia[i] = false;
										dia[0] = true;
										darkness = 255;
										loadTextsStage_denial();
										//itt ebben a pillanatban meg is halsz
									}
								}
								else if (dia[5])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										b_stage7 = false;
										b_stage_denial = true;
										for (int i = 0; i < 6; ++i)
											dia[i] = false;
										dia[0] = true;
										darkness = 255;
										loadTextsStage_denial();
										//itt ebben a pillanatban meg is halsz
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										changeDialogStage7();
										if (meroindex < 6)
											++meroindex;
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										changeDialogStage7();
									}
								}
								else if (dia[6])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										changeDialogStage7();
										if (meroindex > 1)
											--meroindex;
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										changeDialogStage7();
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										changeDialogStage7();
										if (meroindex < 6)
											++meroindex;
									}
								}
								else if (dia[7])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										changeDialogStage7();
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										changeDialogStage7();
										if (meroindex > 1)
											--meroindex;
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										changeDialogStage7();
										if (meroindex < 6)
											++meroindex;
									}
								}
								else if (dia[8])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										changeDialogStage7();
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										changeDialogStage7();
										if (meroindex < 5)
											meroindex += 2;
										else if (meroindex < 6)
											++meroindex;
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										changeDialogStage7();
										if (meroindex < 6)
											++meroindex;
									}
								}
								else if (dia[9])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										if (meroindex > 2)
											meroindex -= 2;
										else if (meroindex > 1)
											--meroindex;
										if (meroindex >= 4)
										{
											b_stage7 = false;
											b_stage_happyending = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_happy3();
										}
										else
										{

											b_stage7 = false;
											b_stage_denial = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_denial();
										}
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										if (meroindex >= 4)
										{
											b_stage7 = false;
											b_stage_happyending = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_happy3();
										}
										else
										{
											b_stage7 = false;
											b_stage_denial = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_denial();
										}
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										changeDialogStage7();
									}
								}
								else if (dia[10])
								{
									if (e.key.keysym.sym == SDLK_1)
									{
										if (meroindex < 6)
											++meroindex;
										if (meroindex >= 4)
										{
											b_stage7 = false;
											b_stage_happyending = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_happy1();					
										}
										else
										{
											b_stage7 = false;
											b_stage_denial = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_denial();
										}
									}
									else if (e.key.keysym.sym == SDLK_2)
									{
										if (meroindex > 2)
											meroindex -= 2;
										else if (meroindex > 1)
											--meroindex;
										if (meroindex >= 4)
										{
											b_stage7 = false;
											b_stage_happyending = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_happy2();
										}
										else
										{
											b_stage7 = false;
											b_stage_denial = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_denial();
										}
									}
									else if (e.key.keysym.sym == SDLK_3)
									{
										if (meroindex >= 4)
										{
											b_stage7 = false;
											b_stage_happyending = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_happy3();
										}
										else
										{
											b_stage7 = false;
											b_stage_denial = true;
											for (int i = 0; i < 6; ++i)
												dia[i] = false;
											dia[0] = true;
											darkness = 255;
											loadTextsStage_denial();
										}
									}
								}
							}
						}
					}
					else if (b_stage_akasztas)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							b_stage_akasztas = false;
							b_mainMenu = true;
							darkness = 255;
						}
						if (Mix_PlayingMusic())
							Mix_HaltMusic();
					}
					else if (b_stage_keseles)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							b_stage_keseles = false;
							b_mainMenu = true;
							darkness = 255;
						}
						if (Mix_PlayingMusic())
							Mix_HaltMusic();
					}
					else if (b_stage_asthma)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							b_stage_asthma = false;
							b_mainMenu = true;
							darkness = 255;
						}
						if (Mix_PlayingMusic())
							Mix_HaltMusic();
					}
					else if (b_stage_denial)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							b_stage_akasztas = true;
							b_stage_denial = false;
							darkness = 255;
							for (int i = 0; i < 6; ++i)
								dia[i] = false;
							dia[0] = true;
							darkness = 255;
							loadTextsStage_akasztas();
						}
					}
					else if (b_stage_happyending)
					{
						if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
						{
							b_stage_happyending = false;
							quit = true;

						}
					}
				}

				///Cleaning
				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
				SDL_RenderClear(Renderer);

				///Main Menu
				//To do: gomb aktivalas, hatter, szoveg
				if (b_mainMenu)
				{
					mainMenu.render(0, 0, NULL);
					buttons[0].render(buttons[0].getPosx(), buttons[0].getPosy(), NULL);
					mainMenuText.render(SCREEN_WIDTH / 2 - mainMenuText.getWidth() / 2, 0, NULL);
				}
				else if (b_stage0)
				{
					//transition
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					//textures
					kastely.renderAnimation(0, 0, NULL);
					blackTrans.render(0, 0, NULL);
					textBox.render(0, 0, NULL);

					///text transition///
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
						else if (textTransition6.w < textBoxtext6.getWidth())
							textTransition6.w += SPEED;
					}
					else if (dia[1])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}

					///text rendering///
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
						textBoxtext4.render(300, 590, &textTransition4);
						textBoxtext5.render(300, 610, &textTransition5);
						textBoxtext6.render(300, 630, &textTransition6);
					}
					else if (dia[1])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
						textBoxtext4.render(300, 590, &textTransition4);
					}

				}
				else if (b_stage1)
				{
					//transition
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					//textures
					kastely_belso.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					//characters
					king.render(1050, 450, NULL);
					hero.render(40, 500, NULL);

					//*text transition*//
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						//else if() - > rendereli a kovi sort fokozatosan a masik utan
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					else if (dia[1])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
					}
					else if (dia[2])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}
					else if (dia[3])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;

					}
					else if (dia[4])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}

					//*text rendering*//
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
					}
					else if (dia[1])
					{
						textBoxtext1.render(300, 530, &textTransition1);
					}
					else if (dia[2])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
					}
					else if (dia[3])
					{
						textBoxtext1.render(300, 530, &textTransition1);
					}
					else if (dia[4])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
					}

				}
				else if (b_stage2)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					//textures//
					hid.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					//characters
					hero.render(40, 450, NULL);
					goblin.render(1050, 500, NULL);


					//*text transition*//
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}
					else if (dia[1])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					else if (dia[2])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					else if (dia[3])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					//*text rendering*//
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);

					}
					else if (dia[1])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
					}
					else if (dia[2])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
					}
					else if (dia[3])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}

				}
				else if (b_stage3)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}


					banyaBejar.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					//characters
					hero.render(40, 500, NULL);
					miner.render(1050, 500, NULL);

					//*text transition*//
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}
					else if (dia[1])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}
					else if (dia[2])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}
					else if (dia[3])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
						else if (textTransition6.w < textBoxtext6.getWidth())
							textTransition6.w += SPEED;
					}
					else if (dia[4])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}


					//*text rendering*//
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
					}
					else if (dia[1])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
					}
					else if (dia[2])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
					}
					else if (dia[3])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 580, &textTransition3);
						textBoxtext4.render(300, 610, &textTransition4);
						textBoxtext5.render(300, 630, &textTransition5);
						textBoxtext6.render(300, 650, &textTransition6);
					}
					else if (dia[4])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 550, &textTransition2);
						textBoxtext3.render(300, 570, &textTransition3);
					}
				}
				else if (b_stage4)
				{
					halalSotet.render(0, 0, NULL);
					textBox.render(0, 0, NULL);

					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}

					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
					}
				}
				else if (b_stage5)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
						Mix_VolumeMusic(128 - darkness);
					}

					banyaBelso.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}

					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 570, &textTransition2);
						textBoxtext3.render(300, 600, &textTransition3);
						textBoxtext4.render(300, 630, &textTransition4);
					}
				}
				else if (b_stage6)
				{

					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}
					else if (toLeft < SCREEN_WIDTH - 1100)
					{
						++toLeft;
					}


					cave.render(-toLeft, SCREEN_HEIGHT - cave.getHeight(), NULL);
					hero.render((SCREEN_WIDTH - 1100) - toLeft, 500, NULL);
					princess.render(SCREEN_WIDTH - toLeft, 500, NULL);
					blackTrans.render(0, 0, NULL);
					if (toLeft >= SCREEN_WIDTH - 1100)
					{
						textBox.render(0, 0, NULL);
						if (dia[0])
						{
							if (textTransition1.w < textBoxtext1.getWidth())
								textTransition1.w += SPEED;
							else if (textTransition2.w < textBoxtext2.getWidth())
								textTransition2.w += SPEED;
						}
						else if (dia[1])
						{
							if (textTransition1.w < textBoxtext1.getWidth())
								textTransition1.w += SPEED;
							else if (textTransition2.w < textBoxtext2.getWidth())
								textTransition2.w += SPEED;
							else if (textTransition3.w < textBoxtext3.getWidth())
								textTransition3.w += SPEED;
							else if (textTransition4.w < textBoxtext4.getWidth())
								textTransition4.w += SPEED;
							else if (textTransition5.w < textBoxtext5.getWidth())
								textTransition5.w += SPEED;
						}

						if (dia[0])
						{
							textBoxtext1.render(300, 530, &textTransition1);
							textBoxtext2.render(300, 570, &textTransition2);
						}
						else if (dia[1])
						{
							textBoxtext1.render(300, 530, &textTransition1);
							textBoxtext2.render(300, 560, &textTransition2);
							textBoxtext3.render(300, 590, &textTransition3);
							textBoxtext4.render(300, 620, &textTransition4);
							textBoxtext5.render(300, 650, &textTransition5);
						}
					}

				}
				else if (b_stage7)
				{

					cave.render(-toLeft, SCREEN_HEIGHT - cave.getHeight(), NULL);
					hero.render((SCREEN_WIDTH - 1100) - toLeft, 500, NULL);
					princess.render(SCREEN_WIDTH - toLeft, 500, NULL);
					textBox.render(0, 0, NULL);
					mero[meroindex].render(0, 0, NULL);
					lovemeter.render(50, 185, NULL);

					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					else if (dia[1])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}
					else if (dia[2])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
					}
					else if (dia[3])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
					}
					else if (dia[4])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}
					else if (dia[5])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}
					else if (dia[6])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
					}
					else if (dia[7])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
						else if (textTransition6.w < textBoxtext6.getWidth())
							textTransition6.w += SPEED;
					}
					else if (dia[8])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
						else if (textTransition6.w < textBoxtext6.getWidth())
							textTransition6.w += SPEED;
					}
					else if (dia[9])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
						else if (textTransition5.w < textBoxtext5.getWidth())
							textTransition5.w += SPEED;
					}
					else if (dia[10])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}

					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}
					else if (dia[1])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}
					else if (dia[2])
					{
						textBoxtext1.render(300, 530, &textTransition1);
					}
					else if (dia[3])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
						textBoxtext5.render(300, 650, &textTransition5);
					}
					else if (dia[4])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
					}
					else if (dia[5])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
					}
					else if (dia[6])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
						textBoxtext5.render(300, 650, &textTransition5);
					}
					else if (dia[7])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
						textBoxtext5.render(300, 650, &textTransition5);
						textBoxtext6.render(300, 680, &textTransition6);
					}
					else if (dia[8])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
						textBoxtext5.render(300, 650, &textTransition5);
						textBoxtext6.render(300, 680, &textTransition6);
					}
					else if (dia[9])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
						textBoxtext5.render(300, 650, &textTransition5);
					}
					else if (dia[10])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
					}
				}
				else if (b_stage_denial)
				{

					cave.render(-toLeft, SCREEN_HEIGHT - cave.getHeight(), NULL);
					hero.render((SCREEN_WIDTH - 1100) - toLeft, 500, NULL);
					princess.render(SCREEN_WIDTH - toLeft, 500, NULL);
					textBox.render(0, 0, NULL);
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
						else if (textTransition4.w < textBoxtext4.getWidth())
							textTransition4.w += SPEED;
					}
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
						textBoxtext4.render(300, 620, &textTransition4);
					}
				}
				else if (b_stage_akasztas)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}


					halalSotet.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					gameOver.render((SCREEN_WIDTH - gameOver.getWidth()) / 2, (SCREEN_HEIGHT - gameOver.getHeight()) / 2, NULL);
					akasztott.render((SCREEN_WIDTH - akasztott.getWidth()) / 2, (SCREEN_HEIGHT - akasztott.getHeight()) / 2 + 7, NULL);
					blackTrans.render(0, 0, NULL);

					///text Transition*//
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
					}

					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
					}
				}

				else if (b_stage_keseles)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					halalSotet.render(0, 0, NULL);
					keseles.render((SCREEN_WIDTH - keseles.getWidth()) / 2, (SCREEN_HEIGHT - keseles.getHeight()) / 2, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					//textTranstiion
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}

					//text rendering
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}
				}

				else if (b_stage_happyending)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					halalSotet.render(0, 0, NULL);
					ending.render((SCREEN_WIDTH - ending.getWidth()) / 2, (SCREEN_HEIGHT - ending.getHeight()) / 2, NULL);
					blackTrans.render(0, 0, NULL);
					textBox.render(0, 0, NULL);
					
					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}

					//text rendering
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}
				}

				else if (b_stage_asthma)
				{
					if (darkness > 0)
					{
						darkness -= SPEED;
						blackTrans.setAlpha(darkness);
					}

					halalSotet.render(0, 0, NULL);
					asthma.render((SCREEN_WIDTH - asthma.getWidth()) / 2, (SCREEN_HEIGHT - asthma.getHeight()) / 2, NULL);
					textBox.render(0, 0, NULL);
					blackTrans.render(0, 0, NULL);

					if (dia[0])
					{
						if (textTransition1.w < textBoxtext1.getWidth())
							textTransition1.w += SPEED;
						else if (textTransition2.w < textBoxtext2.getWidth())
							textTransition2.w += SPEED;
						else if (textTransition3.w < textBoxtext3.getWidth())
							textTransition3.w += SPEED;
					}

					//text rendering
					if (dia[0])
					{
						textBoxtext1.render(300, 530, &textTransition1);
						textBoxtext2.render(300, 560, &textTransition2);
						textBoxtext3.render(300, 590, &textTransition3);
					}
				}

				SDL_RenderPresent(Renderer);




			}
		}
	}
	close();
}
