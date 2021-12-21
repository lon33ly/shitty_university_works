import re


def main():
    input_str = str(input())

    vowel_chars = list('аеёиоуыэюя')
    consonant_chars = list('бвгджзйклмнпрстфхцчшщъь')
    vowel_count = 0
    consonant_count = 0

    for ch in input_str.lower():
        if ch in vowel_chars:
            vowel_count += 1
        elif ch in consonant_chars:
            consonant_count += 1

    vowel_percent = vowel_count / (len(input_str) / 100)
    consonant_percent = consonant_count / (len(input_str) / 100)
    print(f"Гласных в процентах от всех символов: {vowel_percent}")
    print(f"Согласных в процентах от всех символов: {consonant_percent}")

    words_list = re.sub(r"[^\w]", " ", input_str).split()  # вычленяем слова из строки
    min_len_of_word = 99999  # инициализируем для поиска минимального слова по длине
    min_word = str()

    for word in words_list:
        if len(word) < min_len_of_word:
            min_word = word
            min_len_of_word = len(word)

    print(f"Слово минимальной длины \"{min_word}\", его длина: {min_len_of_word}")


if __name__ == "__main__":
    main()
