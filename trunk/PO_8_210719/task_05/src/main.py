import sys
import sqlite3
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Коллекция компакт-дисков")
        self.setGeometry(100, 100, 600, 400)

        # Создание кнопок для выполнения запросов
        self.btn_artistic = QPushButton("Количество записей по artistic", self)
        self.btn_artistic.setGeometry(50, 50, 300, 30)
        self.btn_artistic.clicked.connect(self.count_artistic)

        self.btn_title = QPushButton("Количество записей по title", self)
        self.btn_title.setGeometry(50, 100, 300, 30)
        self.btn_title.clicked.connect(self.count_title)

        self.btn_year = QPushButton("Количество записей по year", self)
        self.btn_year.setGeometry(50, 150, 300, 30)
        self.btn_year.clicked.connect(self.count_year)

        # Виджет для отображения данных из базы данных
        self.table_widget = QTableWidget(self)
        self.table_widget.setGeometry(50, 200, 500, 150)

        # Установка соединения с базой данных SQLite
        self.connection = sqlite3.connect('collection.db')
        self.cursor = self.connection.cursor()

        # Создание таблиц
        self.create_tables()

    def create_tables(self):
        create_table_artist = '''CREATE TABLE IF NOT EXISTS artist (
                                    id INTEGER PRIMARY KEY,
                                    name TEXT,
                                    country TEXT
                                )'''

        create_table_cd = '''CREATE TABLE IF NOT EXISTS cd (
                                id INTEGER PRIMARY KEY,
                                artistic INTEGER,
                                title TEXT,
                                year INTEGER,
                                FOREIGN KEY (artistic) REFERENCES artist(id)
                            )'''

        create_table_track = '''CREATE TABLE IF NOT EXISTS track (
                                    id INTEGER PRIMARY KEY,
                                    cdid INTEGER,
                                    number INTEGER,
                                    title TEXT,
                                    duration TEXT,
                                    FOREIGN KEY (cdid) REFERENCES cd(id)
                                )'''

        self.cursor.execute(create_table_artist)
        self.cursor.execute(create_table_cd)
        self.cursor.execute(create_table_track)
        self.connection.commit()

    def count_artistic(self):
        query = '''SELECT artistic, COUNT(*) FROM cd GROUP BY artistic'''
        self.cursor.execute(query)
        result = self.cursor.fetchall()
        self.show_result_in_table(result)

    def count_title(self):
        query = '''SELECT title, COUNT(*) FROM cd GROUP BY title'''
        self.cursor.execute(query)
        result = self.cursor.fetchall()
        self.show_result_in_table(result)

    def count_year(self):
        query = '''SELECT year, COUNT(*) FROM cd GROUP BY year'''
        self.cursor.execute(query)
        result = self.cursor.fetchall()
        self.show_result_in_table(result)

    def show_result_in_table(self, result):
        self.table_widget.clear()
        self.table_widget.setRowCount(len(result))
        self.table_widget.setColumnCount(len(result[0]))

        for i, row in enumerate(result):
            for j, col in enumerate(row):
                item = QTableWidgetItem(str(col))
                self.table_widget.setItem(i, j, item)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
