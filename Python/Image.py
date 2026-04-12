from tkinter import*
tk = Tk()
canvas = Canvas(tk, width = 400, height = 400)
canvas.pack()
my_image = PhotoImage(file = 'path/to/your/image')
canvas.create_image(0,0,anchor = NW, image = my_image)
