build:
		cl /c ConnectFour.c
		lib /OUT: ConnectFour.lib ConnectFour.obj
		cl /c ConnectFour.c
		link ConnectFour.obj ConnectFour.lib
		del *.obj
		

clean:
		del *.exe
		del *.obj