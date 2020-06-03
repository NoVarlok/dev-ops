FROM python:3

#ADD include/Deanery.h /
#ADD include/Group.h /
#ADD include/Student.h /
#ADD src/Deanery.cpp /
#ADD src/Group.cpp /
#ADD src/Student.cpp /
#ADD src/main.cpp /

ADD Deanery.h /
ADD Group.h /
ADD Student.h /

RUN pip install cpplint

RUN cpplint --verbose=2 Deanery.h
RUN cpplint --verbose=2 Group.h
RUN cpplint --verbose=2 Student.h
#RUN cpplint --verbose=2 Deanery.cpp
#RUN cpplint --verbose=2 Group.cpp
#RUN cpplint --verbose=2 Student.cpp
#RUN cpplint --verbose=2 main.cpp
