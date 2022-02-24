import random
from colorama import init, Fore


class Quest:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.compztz = 1
        self.min_inds = []
        self.d_list = []
        self.sowed_zeros = 0

    @staticmethod
    def setup_for_console():
        """Создание экземпляра класса и запуск функций в нужном порядке"""
        q1 = Quest()
        q1.input_n_and_m()
        q1.create_2d_list()
        q1.print_2d_list()
        q1.find_index_min_els()
        q1.print_indices_of_min_els()
        q1.sow_zero_elements(int(input("Сколько нулей нужно посеять?\n")))
        q1.print_2d_list()
        q1.find_comp_from_zero_to_zero(int(input("C какого нуля получить перемножение?\n")))
        q1.replace_odd_and_even_indices_by_half()
        q1.print_2d_list()

    def input_n_and_m(self):
        self.m = int(input("Введите m: "))
        self.n = int(input("Введите n: "))

    def create_2d_list(self, size_rand=30):
        for i in range(self.m):
            self.d_list.append(random.sample(range(1, size_rand), self.n))

    def print_2d_list(self):
        print("Двумерный список:")
        for i in range(self.m):
            for j in range(self.n):
                if self.d_list[i][j] == 0:
                    print(Fore.BLUE + f"{self.d_list[i][j]:3}", end="")
                else:
                    print(f"{self.d_list[i][j]:3}", end="")
            print()

    def find_index_min_els(self):
        """Ищутся элементы минимальных элементов, а затем они записываются в поле класса"""
        min_el = 9999
        for i in range(self.m):
            for j in range(self.n):
                if self.d_list[i][j] < min_el:
                    self.min_inds.clear()
                    self.min_inds.append([i, j])
                    min_el = self.d_list[i][j]
                elif self.d_list[i][j] == min_el:
                    self.min_inds.append([i, j])

    def print_indices_of_min_els(self):
        print(f"Значение минимальных элементов:{self.d_list[self.min_inds[0][0]][self.min_inds[0][1]]}")
        print(f"Индексы минимальных элементов: ")
        print(f"Строка Столбец")
        for el in self.min_inds:
            print(f"{el[0] + 1:6} {el[1] + 1:7}")

    def sow_zero_elements(self, count_z=2):
        """
        Сеются нулевые элементы в неповторяющихся индексах
        количество нулей можно задать при вызове метода
        """
        self.sowed_zeros = count_z
        print(f"*** Посеяны {count_z} нуля ***")
        flag = 0
        for i in range(count_z):
            while flag < count_z:
                i = random.randint(0, self.m - 1)
                j = random.randint(0, self.n - 1)
                if self.d_list[i][j] != 0:
                    flag += 1
                    self.d_list[i][j] = 0

    def find_comp_from_zero_to_zero(self, start_zero=1):
        if start_zero < self.sowed_zeros:
            end_zero = start_zero + 1
            zero_counter = 0
            for i in range(self.m):
                for j in range(self.n):
                    if self.d_list[i][j] == 0:
                        zero_counter += 1
                    if zero_counter == start_zero and self.d_list[i][j] != 0:
                        self.compztz *= self.d_list[i][j]
            print(f"Результат перемножения с {start_zero} по {end_zero} ноль = {self.compztz}")
        else:
            print(f"После {self.sowed_zeros} больше нет нулей!")

    def replace_odd_and_even_indices_by_half(self):
        """
        Продвижение идет последовательно, каждый четный элемент помещается в первую
        половину,
        а не четный во вторую
        """
        hidden_index = 0
        for i in range(self.m):
            for j in range(self.n):
                if (i * self.n + j) % 2 == 0:
                    tmp_number = i * self.n + j - hidden_index
                    row = tmp_number // self.n
                    col = tmp_number % self.n
                    tmptmp = self.d_list[row][col]
                    self.d_list[row][col] = self.d_list[i][j]
                    self.d_list[i][j] = tmptmp
                    hidden_index += 1
        print("Элементы с четными индексами перенесены в первую половину двумерного списка.")


# запуск программы
if __name__ == '__main__':
    init(autoreset=True)
    Quest.setup_for_console()
