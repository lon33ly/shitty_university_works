class Quest1:
    def __init__(self):
        self.number = 0
        self.index = 0
        self.count = 0
        self.digit = 0
        self.divider_list = list()
        self.divider_dict = dict()

    @staticmethod
    def setup_for_console():
        q1 = Quest1()
        q1.input_number_and_index()
        q1.digit_count()
        q1.slice_digit_by_index()
        print(f"Цифра: {q1.digit}")
        q1.input_dividers()
        q1.check_divisibility()
        print(f"Делимости:\n{q1.divider_dict}")

    def input_number_and_index(self):
        self.number = int(input("Введите число: "))
        self.index = int(input("Введите индекс цифры: "))

    def input_dividers(self):
        count = int(input("Введите количество делителей: "))
        for i in range(count):
            self.divider_list.append(int(input(f"Введите {i+1} делитель: ")))

    def digit_count(self):
        tmp_number = self.number
        while tmp_number > 0:
            tmp_number //= 10
            self.count += 1

    def slice_digit_by_index(self):
        tmp_number = self.number
        if self.count > self.index:
            for i in range(self.count - self.index):
                tmp_number //= 10

        self.digit = tmp_number % 10

    def check_divisibility(self):
        for divider in self.divider_list:
            self.divider_dict[f"{divider}"] = not bool(self.number % divider)


class Quest2:
    def __init__(self, start=10, stop=100):
        self.list1 = [i for i in range(start, stop)]
        self.list2 = [i for i in range(start, stop)]
        self.list_2_8 = list()
        self.list_3_4 = list()

    @staticmethod
    def setup_for_console():
        q2 = Quest2()
        q2.find_last_digit()
        print(f"При умножении на 2 - конец 8: {q2.list_2_8}\n"
              f"При умножении на 3 - конец 4: {q2.list_3_4}\n"
              f"{len(q2.list1)}")

    def find_last_digit(self):
        for i in range(len(self.list1)):
            if self.list1[i]*2 % 10 == 8:
                self.list_2_8.append(self.list1[i])
            if self.list2[i]*3 % 10 == 4:
                self.list_3_4.append((self.list2[i]))


if __name__ == "__main__":
    Quest1.setup_for_console()
    Quest2.setup_for_console()
