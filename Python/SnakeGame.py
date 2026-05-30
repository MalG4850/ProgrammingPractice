import random
import time
import turtle
from enum import Enum, auto
from typing import List


class Direction(Enum):
    """Enumeration for snake movement directions."""
    UP = auto()
    DOWN = auto()
    LEFT = auto()
    RIGHT = auto()
    STOP = auto()


class SnakeGame:
    """A simple Snake game using the turtle module."""

    def __init__(self) -> None:
        # Screen Setup
        self.screen = turtle.Screen()
        self.screen.title("Snake Game: Modernized")
        self.screen.setup(width=800, height=700)
        self.screen.tracer(0)
        
        # Grid and Border Turtles
        self.grid_drawer = turtle.Turtle()
        self.grid_drawer.hideturtle()
        self.grid_drawer.speed(0)
        
        self.border_drawer = turtle.Turtle()
        self.border_drawer.hideturtle()
        self.border_drawer.speed(0)

        # Game Objects
        self.snake = self._create_turtle("square", "black", (10, 10))
        self.fruit = self._create_turtle("circle", "red", (50, 50))
        self.scoring = self._create_scoring_turtle()
        self.game_over_text = self._create_overlay_turtle()
        
        self.segments: List[turtle.Turtle] = []
        self.is_running: bool = True
        
        self._setup_bindings()
        self._reset_game()

    def _reset_game(self) -> None:
        """Resets the game state to initial values."""
        self.score = 0
        self.delay = 0.1
        self.game_active = True
        self.current_direction = Direction.STOP
        self.can_change_direction = True # Lock for tick-based movement
        
        # Clean up segments
        for segment in self.segments:
            segment.goto(1000, 1000)
            segment.hideturtle()
        self.segments.clear()
        
        # Reset positions
        self.snake.goto(10, 10)
        self.fruit.goto(50, 50)
        self.fruit.showturtle()
        self.snake.showturtle()
        
        self.screen.bgcolor("light grey")
        self.game_over_text.clear()
        
        # Redraw visuals
        self.grid_drawer.clear()
        self.border_drawer.clear()
        self._draw_grid()
        self._draw_border()
        
        # Reset score display
        self.scoring.clear()
        self.scoring.write("Score: 0", align="center", font=("Courier", 24, "bold"))

    def _create_turtle(
        self, shape: str, color: str, position: tuple[int, int]
    ) -> turtle.Turtle:
        """Helper to create and position a turtle object."""
        t = turtle.Turtle()
        t.shape(shape)
        t.color(color)
        t.penup()
        t.goto(position)
        return t

    def _create_scoring_turtle(self) -> turtle.Turtle:
        """Creates the turtle used for displaying the score."""
        t = turtle.Turtle()
        t.speed(0)
        t.penup()
        t.hideturtle()
        t.goto(0, 260)
        return t

    def _create_overlay_turtle(self) -> turtle.Turtle:
        """Creates the turtle used for game over messages."""
        t = turtle.Turtle()
        t.hideturtle()
        t.penup()
        t.color("white")
        t.goto(0, 0)
        return t

    def _draw_grid(self) -> None:
        """Draws the background grid."""
        self.grid_drawer.penup()
        self.grid_drawer.color("#A0A0A0")
        self.grid_drawer.pensize(1)

        for x in range(-300, 320, 20):
            self.grid_drawer.goto(x, 240)
            self.grid_drawer.pendown()
            self.grid_drawer.goto(x, -240)
            self.grid_drawer.penup()

        for y in range(-240, 260, 20):
            self.grid_drawer.goto(-300, y)
            self.grid_drawer.pendown()
            self.grid_drawer.goto(300, y)
            self.grid_drawer.penup()

    def _draw_border(self) -> None:
        """Draws the play area border."""
        self.border_drawer.pensize(4)
        self.border_drawer.penup()
        self.border_drawer.goto(-300, 240)
        self.border_drawer.pendown()
        self.border_drawer.color("black")
        for _ in range(2):
            self.border_drawer.forward(600)
            self.border_drawer.right(90)
            self.border_drawer.forward(480)
            self.border_drawer.right(90)

    def _setup_bindings(self) -> None:
        """Sets up keyboard event listeners."""
        self.screen.listen()
        # Arrow keys
        self.screen.onkeypress(self.go_up, "Up")
        self.screen.onkeypress(self.go_down, "Down")
        self.screen.onkeypress(self.go_left, "Left")
        self.screen.onkeypress(self.go_right, "Right")
        # WASD
        self.screen.onkeypress(self.go_up, "w")
        self.screen.onkeypress(self.go_up, "W")
        self.screen.onkeypress(self.go_down, "s")
        self.screen.onkeypress(self.go_down, "S")
        self.screen.onkeypress(self.go_left, "a")
        self.screen.onkeypress(self.go_left, "A")
        self.screen.onkeypress(self.go_right, "d")
        self.screen.onkeypress(self.go_right, "D")
        # Control keys
        self.screen.onkeypress(self.restart, "r")
        self.screen.onkeypress(self.restart, "R")
        self.screen.onkeypress(self.exit_game, "space")

    def go_up(self) -> None:
        if self.can_change_direction and self.current_direction != Direction.DOWN:
            self.current_direction = Direction.UP
            self.can_change_direction = False

    def go_down(self) -> None:
        if self.can_change_direction and self.current_direction != Direction.UP:
            self.current_direction = Direction.DOWN
            self.can_change_direction = False

    def go_left(self) -> None:
        if self.can_change_direction and self.current_direction != Direction.RIGHT:
            self.current_direction = Direction.LEFT
            self.can_change_direction = False

    def go_right(self) -> None:
        if self.can_change_direction and self.current_direction != Direction.LEFT:
            self.current_direction = Direction.RIGHT
            self.can_change_direction = False

    def restart(self) -> None:
        """Restarts the game if it is currently over."""
        if not self.game_active:
            self._reset_game()

    def exit_game(self) -> None:
        """Exits the game application."""
        self.is_running = False
        try:
            self.screen.bye()
        except turtle.Terminator:
            pass

    def move(self) -> None:
        """Moves the snake's head based on current direction."""
        match self.current_direction:
            case Direction.UP:
                self.snake.sety(self.snake.ycor() + 20)
            case Direction.DOWN:
                self.snake.sety(self.snake.ycor() - 20)
            case Direction.LEFT:
                self.snake.setx(self.snake.xcor() - 20)
            case Direction.RIGHT:
                self.snake.setx(self.snake.xcor() + 20)
            case _:
                pass

    def end_game(self) -> None:
        """Ends the game and displays final score and options."""
        self.game_active = False
        
        # Visual cleanup for Game Over
        self.grid_drawer.clear()
        self.border_drawer.clear()
        self.snake.hideturtle()
        self.fruit.hideturtle()
        for segment in self.segments:
            segment.hideturtle()
        
        self.screen.bgcolor("black")
        self.game_over_text.write(
            f"GAME OVER\nFinal Score: {self.score}\n\n"
            "Press 'R' to Restart\n"
            "Press SPACE to Exit",
            align="center",
            font=("Courier", 24, "bold"),
        )

    def run(self) -> None:
        """Main game loop."""
        while self.is_running:
            self.screen.update()

            if self.game_active:
                # Allow direction change for this tick
                self.can_change_direction = True
                
                # Border Collision
                if (
                    abs(self.snake.xcor()) > 290
                    or self.snake.ycor() > 230
                    or self.snake.ycor() < -230
                ):
                    self.end_game()
                    continue

                # Fruit Collision
                if self.snake.distance(self.fruit) < 15:
                    x = (random.randint(-15, 14) * 20) + 10
                    y = (random.randint(-12, 11) * 20) + 10
                    self.fruit.goto(x, y)

                    self.score += 1
                    self.scoring.clear()
                    self.scoring.write(
                        f"Score: {self.score}", align="center", font=("Courier", 24, "bold")
                    )
                    self.delay = max(0.04, self.delay - 0.002)

                    new_segment = turtle.Turtle()
                    new_segment.shape("square")
                    new_segment.color("forest green")
                    new_segment.penup()
                    self.segments.append(new_segment)

                # Move Body segments
                head_x, head_y = self.snake.xcor(), self.snake.ycor()
                
                # Check for self-collision
                if self.current_direction != Direction.STOP:
                    for segment in self.segments:
                        if segment.distance(self.snake) < 10:
                            self.end_game()
                            break
                    if not self.game_active: continue

                # Move body segments
                for index in range(len(self.segments) - 1, 0, -1):
                    self.segments[index].goto(
                        self.segments[index - 1].xcor(), self.segments[index - 1].ycor()
                    )
                if self.segments:
                    self.segments[0].goto(head_x, head_y)

                self.move()
                time.sleep(self.delay)
            else:
                time.sleep(0.1)

        try:
            self.screen.exitonclick()
        except turtle.Terminator:
            pass


if __name__ == "__main__":
    game = SnakeGame()
    game.run()
