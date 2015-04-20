Test: testcp.o person.o student.o staff.o faculty.o employee.o
	c++ testcp.o person.o student.o staff.o faculty.o employee.o -o Test
testcp.o: testcp.cpp 
	c++ -c testcp.cpp
student.o: student.cpp person.cpp
	c++ -c student.cpp
faculty.o: faculty.cpp employee.cpp
	c++ -c faculty.cpp
employee.o: employee.cpp person.cpp
	c++ -c employee.cpp
staff.o: staff.cpp employee.cpp
	c++ -c staff.cpp
person.o: person.cpp
	c++ -c person.cpp