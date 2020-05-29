# Сборка ---------------------------------------

# В качестве базового образа для сборки используем gcc:latest
FROM gcc:latest as build

WORKDIR /app/build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      cmake

# Скопируем директорию /src в контейнер
ADD ./src /app/src
ADD ./include /app/src
ADD ./cmake /app/src


# Выполним сборку нашего проекта, а также его тестирование
RUN cmake ../src && \
    cmake --build .

# Запуск ---------------------------------------

# В качестве базового образа используем ubuntu:latest
FROM ubuntu:latest

# Добавим пользователя, потому как в Docker по умолчанию используется root
# Запускать незнакомое приложение под root'ом неприлично :)
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# Установим рабочую директорию нашего приложения
WORKDIR /app

# Скопируем приложение со сборочного контейнера в рабочую директорию
COPY --from=build /app/build/deanery_app .

# Установим точку входа
# RUN ls
ENTRYPOINT ["./deanery_app"]