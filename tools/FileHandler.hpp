/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** file_handler
*/

#ifndef FILE_HANDLER_HPP_
#define FILE_HANDLER_HPP_
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

class File {
  public:
    File(const std::string& fpath);
    File() = default;
    ~File();
    std::string getContent();
    void open(std::string fpath);

    class InvalidFileOperation : std::exception {
      public:
        InvalidFileOperation(const std::string msg) noexcept;
        const char* what() const noexcept override;

      private:
        std::string _msg;
    };

  private:
    const std::string _path;
    std::ifstream _stream;
};

#endif /* !FILE_HANDLER_HPP_ */
