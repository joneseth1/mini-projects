import tkinter as tk
from tkinter import messagebox


class TimeTrackerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Time Tracker")
        self.total_minutes = 0

        # Labels
        self.title_label = tk.Label(root, text="Time Tracker", font=("Arial", 16))
        self.title_label.pack(pady=10)

        self.total_label = tk.Label(root, text=f"Total Minutes: {self.total_minutes}", font=("Arial", 14))
        self.total_label.pack(pady=10)

        # Entry for adding minutes
        self.minutes_label = tk.Label(root, text="Enter Minutes to Add:", font=("Arial", 12))
        self.minutes_label.pack(pady=5)
        self.minutes_entry = tk.Entry(root, width=10, font=("Arial", 12))
        self.minutes_entry.pack(pady=5)

        # Buttons
        self.add_button = tk.Button(root, text="Add Minutes", font=("Arial", 12), command=self.add_minutes)
        self.add_button.pack(pady=5)

        self.clear_button = tk.Button(root, text="Clear Total", font=("Arial", 12), command=self.clear_total)
        self.clear_button.pack(pady=5)

        self.exit_button = tk.Button(root, text="Exit", font=("Arial", 12), command=root.quit)
        self.exit_button.pack(pady=20)

    def add_minutes(self):
        try:
            minutes = int(self.minutes_entry.get())
            if minutes < 0:
                messagebox.showerror("Invalid Input", "Cannot add negative minutes.")
            else:
                self.total_minutes += minutes
                self.update_total_label()
                messagebox.showinfo("Success", f"{minutes} minutes added.")
            self.minutes_entry.delete(0, tk.END)  # Clear the input field
        except ValueError:
            messagebox.showerror("Invalid Input", "Please enter a valid number.")

    def clear_total(self):
        self.total_minutes = 0
        self.update_total_label()
        messagebox.showinfo("Success", "Total minutes cleared.")

    def update_total_label(self):
        self.total_label.config(text=f"Total Minutes: {self.total_minutes}")


if __name__ == "__main__":
    root = tk.Tk()
    app = TimeTrackerApp(root)
    root.mainloop()

