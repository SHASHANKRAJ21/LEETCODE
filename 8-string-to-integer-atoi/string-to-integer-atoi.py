class Solution:
  def myAtoi(self, s: str) -> int:
        res = 0
        f = 1
        s = s.strip(" ")
        if len(s) == 0:
            return 0
        elif s[0] == "-":
            f = -1
        elif s[0] == "+":
            f = 1
        elif s[0].isalpha() or s[0] == ".":
            return 0
        else:
            res += int(s[0])


        for ch in s[1:]:
            if ch.isdigit():
                res = res * 10 + int(ch)
            else:
                break
        return min(max(-2**31, res * f), 2**31-1)
        