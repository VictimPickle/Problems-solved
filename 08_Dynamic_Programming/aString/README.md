# aString

## English Summary
Given a string of length $n=2^s$ consisting of lowercase Latin letters, determine the minimum number of moves required to transform the string into an "a-good" string. A string is considered "a-good" if one of the following conditions is met:
1. The string is a single letter "a".
2. The first half of the string is entirely composed of letter "a" and the second half is a "(a+1)-good" string.
3. The second half of the string is entirely composed of letter "a" and the first half is a "(a+1)-good" string. You can choose an index from 1 to n in each move and change the corresponding letter in the string.

## Persian Summary / خلاصه فارسی
در این مسئله باید تعداد حداقل حرکات مورد نیاز برای تبدیل یک رشته به یک رشته a-خوب را محاسبه کنید. یک رشته a-خوب به یکی از سه حالت زیر تعلق دارد: 1. رشته تک‌حرف "a" باشد. 2. نیمه اول رشته تماماً از حرف a تشکیل شده باشد و نیمه دوم رشته (a+1)-خوب باشد. 3. نیمه دوم رشته تماماً از حرف a تشکیل شده باشد و نیمه اول رشته (a+1)-خوب باشد. در هر حرکت می‌توانید یک اندیس از ۱ تا n را انتخاب کرده و حرف متناظر آن اندیس را تغییر دهید.