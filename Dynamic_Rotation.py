import pygame
import sys
from math import radians, sin, cos

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

class Arm:
    def __init__(self):
        # Joint angles
        self.theta1 = 0
        self.theta2 = 0
        self.theta3 = 0

        # Target angles
        self.target_theta1 = 30
        self.target_theta2 = 55
        self.target_theta3 = 60

        # Arm dimensions
        self.base_length = 100
        self.link1_length = 150
        self.link2_length = 100
        self.link3_length = 80

    def update(self):
        # Smoothly transition from current angles to target angles
        self.theta1 += (self.target_theta1 - self.theta1) * 0.05
        self.theta2 += (self.target_theta2 - self.theta2) * 0.05
        self.theta3 += (self.target_theta3 - self.theta3) * 0.05

    def draw(self, screen):
        base_x = SCREEN_WIDTH // 2
        base_y = SCREEN_HEIGHT // 2

        # Calculate end point of first link
        link1_end_x = base_x + self.link1_length * cos(radians(self.theta1))
        link1_end_y = base_y - self.link1_length * sin(radians(self.theta1))

        # Calculate end point of second link
        link2_end_x = link1_end_x + self.link2_length * cos(radians(self.theta1 + self.theta2))
        link2_end_y = link1_end_y - self.link2_length * sin(radians(self.theta1 + self.theta2))

        # Calculate end point of third link
        link3_end_x = link2_end_x + self.link3_length * cos(radians(self.theta1 + self.theta2 + self.theta3))
        link3_end_y = link2_end_y - self.link3_length * sin(radians(self.theta1 + self.theta2 + self.theta3))

        # Draw arm
        pygame.draw.line(screen, RED, (base_x, base_y), (int(link1_end_x), int(link1_end_y)), 5)
        pygame.draw.line(screen, GREEN, (int(link1_end_x), int(link1_end_y)), (int(link2_end_x), int(link2_end_y)), 5)
        pygame.draw.line(screen, BLUE, (int(link2_end_x), int(link2_end_y)), (int(link3_end_x), int(link3_end_y)), 5)

    def set_target_angles(self, theta1, theta2, theta3):
        self.target_theta1 = theta1
        self.target_theta2 = theta2
        self.target_theta3 = theta3

def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Robotic Arm")
    clock = pygame.time.Clock()

    arm = Arm()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        arm.update()
        screen.fill(WHITE)
        arm.draw(screen)
        pygame.display.flip()
        clock.tick(30)

if __name__ == "__main__":
    main()
