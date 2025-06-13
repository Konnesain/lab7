import pygame
import sys

width = 1000
height = 200
rectHeight = 50

def drawKantor(x1, width, n, screen):
    if n == 0:
        rect = pygame.Rect(x1, 0, width, rectHeight)
        pygame.draw.rect(screen, (0,0,0), rect, 0)#black rect
        return
    
    part = width/3
    
    #first 1/3
    drawKantor(x1, part, n-1, screen)

    #second 1/3
    #do nothing

    #third 1/3
    drawKantor(x1+part*2, part, n-1, screen)

pygame.init()

screen = pygame.display.set_mode((width, height))

if len(sys.argv) == 2:
    iterations = int(sys.argv[1])
    loop = True
    while(loop):
        screen.fill((255,255,255))#white screen
        drawKantor(5, width-10, iterations, screen)
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                loop = False
        pygame.time.wait(100)
else:
    loop = True
    iterations = 0
    while loop:
        screen.fill((255,255,255))#white screen
        drawKantor(5, width-10, iterations, screen)
        pygame.display.flip()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                loop = False
        pygame.time.wait(1000)
        iterations += 1

pygame.quit()