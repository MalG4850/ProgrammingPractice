import random
import time
import turtle

# --- Configuration & Setup ---
score = 0
delay = 0.1
game_active = True
old_fruit = []
current_direction = "stop"

# Screen Setup
screen = turtle.Screen()
screen.title("Snake Game: True Cell Logic")
screen.setup(width=800, height=700)
screen.tracer(0)
screen.bgcolor("light grey")

# --- Drawing Functions ---


def draw_grid():
    grid_drawer = turtle.Turtle()
    grid_drawer.speed(0)
    grid_drawer.hideturtle()
    grid_drawer.penup()
    grid_drawer.color("#A0A0A0")
    grid_drawer.pensize(1)

    for x in range(-300, 320, 20):
        grid_drawer.goto(x, 240)
        grid_drawer.pendown()
        grid_drawer.goto(x, -240)
        grid_drawer.penup()

    for y in range(-240, 260, 20):
        grid_drawer.goto(-300, y)
        grid_drawer.pendown()
        grid_drawer.goto(300, y)
        grid_drawer.penup()


def draw_border():
    border = turtle.Turtle()
    border.speed(0)
    border.pensize(4)
    border.penup()
    border.goto(-300, 240)
    border.pendown()
    border.color("black")
    for _ in range(2):
        border.forward(600)
        border.right(90)
        border.forward(480)
        border.right(90)
    border.hideturtle()


# --- Movement Logic (With Direction Guards) ---


def go_up():
    global current_direction
    # Only allow Up if we aren't already going Down
    if current_direction != "down":
        current_direction = "up"


def go_down():
    global current_direction
    if current_direction != "up":
        current_direction = "down"


def go_left():
    global current_direction
    if current_direction != "right":
        current_direction = "left"


def go_right():
    global current_direction
    if current_direction != "left":
        current_direction = "right"


def move():
    if current_direction == "up":
        snake.sety(snake.ycor() + 20)
    if current_direction == "down":
        snake.sety(snake.ycor() - 20)
    if current_direction == "left":
        snake.setx(snake.xcor() - 20)
    if current_direction == "right":
        snake.setx(snake.xcor() + 20)


def end_game():
    global game_active
    game_active = False
    time.sleep(0.5)
    screen.clear()
    screen.bgcolor("black")

    end_text = turtle.Turtle()
    end_text.hideturtle()
    end_text.penup()
    end_text.color("white")
    end_text.goto(0, 0)
    end_text.write(
        f"GAME OVER\nFinal Score: {score}\n\nPress SPACE to Exit",
        align="center",
        font=("Courier", 24, "bold"),
    )


# --- Initialization ---

draw_grid()
draw_border()

snake = turtle.Turtle()
snake.shape("square")
snake.color("black")
snake.penup()
snake.goto(10, 10)

fruit = turtle.Turtle()
fruit.shape("circle")
fruit.color("red")
fruit.penup()
fruit.goto(50, 50)

scoring = turtle.Turtle()
scoring.speed(0)
scoring.penup()
scoring.hideturtle()
scoring.goto(0, 260)
scoring.write("Score: 0", align="center", font=("Courier", 24, "bold"))

# Bindings
screen.listen()
screen.onkeypress(go_up, "Up")
screen.onkeypress(go_down, "Down")
screen.onkeypress(go_left, "Left")
screen.onkeypress(go_right, "Right")
screen.onkeypress(go_up, "w")
screen.onkeypress(go_up, "W")
screen.onkeypress(go_down, "s")
screen.onkeypress(go_down, "S")
screen.onkeypress(go_left, "a")
screen.onkeypress(go_left, "A")
screen.onkeypress(go_right, "d")
screen.onkeypress(go_right, "D")
screen.onkeypress(screen.bye, "space")  # Close game on space at the end

# --- Main Game Loop ---
while game_active:
    screen.update()

    # Border Collision
    if (
        snake.xcor() > 290
        or snake.xcor() < -290
        or snake.ycor() > 230
        or snake.ycor() < -230
    ):
        end_game()
        break

    # Fruit Collision
    if snake.distance(fruit) < 15:
        x = (random.randint(-15, 14) * 20) + 10
        y = (random.randint(-12, 11) * 20) + 10
        fruit.goto(x, y)

        score += 1
        scoring.clear()
        scoring.write(f"Score: {score}", align="center", font=("Courier", 24, "bold"))
        delay = max(0.04, delay - 0.002)

        new_segment = turtle.Turtle()
        new_segment.shape("square")
        new_segment.color("forest green")
        new_segment.penup()
        old_fruit.append(new_segment)

    # Move Body segments
    head_x, head_y = snake.xcor(), snake.ycor()
    for index in range(len(old_fruit) - 1, 0, -1):
        old_fruit[index].goto(old_fruit[index - 1].xcor(), old_fruit[index - 1].ycor())
    if len(old_fruit) > 0:
        old_fruit[0].goto(head_x, head_y)

    move()

    # Body Collision
    # Logic: Only check collision if we are actually moving
    if current_direction != "stop":
        for segment in old_fruit:
            if segment.distance(snake) < 10:
                end_game()
                break

    time.sleep(delay)

try:
    screen.exitonclick()
except turtle.Terminator:
    pass
