# Сборка ---------------------------------------

# В качестве базового образа для сборки используем gcc:latest
FROM gcc:latest as build

# Установим рабочую директорию для сборки GoogleTest
WORKDIR /gtest_build

# Скачаем все необходимые пакеты и выполним сборку GoogleTest
# Такая длинная команда обусловлена тем, что
# Docker на каждый RUN порождает отдельный слой,
# Влекущий за собой, в данном случае, ненужный оверхед
RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake \
    && \
    cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build . && \
    mv lib*.a /usr/lib

# Скопируем директорию /src в контейнер
ADD ./src /app/src
ADD ./include /app/src
ADD ./cmake /app/src
ADD ./test /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта, а также его тестирование
RUN cmake ../src && \
    cmake --build . && \
    CTEST_OUTPUT_ON_FAILURE=TRUE cmake --build . --target test
