import pyautogui as pag
import pyperclip
"""
https://m.blog.naver.com/jsk6824/221765884364
https://codetorial.net/pyperclip/index.html
https://wikidocs.net/26
"""
f = open("/home/doit22/src/git/Projects/TxtCopyMacro/simple.txt")
while True:
    line = f.readline()
    if not line: break
    pyperclip.copy(line) #복사
    #x, y = pag.position() 마우스 커서 좌표 추출
    pag.moveTo(0, 0) # 마우스 이동
    pag.click() # 마우스 클릭

    #pag.typewrite("ABC") 키보드 입력
    text_copied = pyperclip.paste() #붙여넣기
f.close()