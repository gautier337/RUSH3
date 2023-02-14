/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** file_handler
*/

#include "FileHandler.hpp"

File::InvalidFileOperation::InvalidFileOperation(const std::string msg) noexcept
    : _msg { msg }
{
}

const char* File::InvalidFileOperation::what() const noexcept { return this->_msg.c_str(); }

File::File(const std::string& fpath)
    : _path { fpath }
    , _stream(fpath)
{
    if (!this->_stream.is_open()) {
        throw InvalidFileOperation(std::strerror(errno));
    }
}

File::~File()
{
    if (this->_stream.is_open()) {
        this->_stream.close();
    }
}

std::string File::getContent()
{
    std::stringstream tmp;

    if (!this->_stream.is_open()) {
        throw InvalidFileOperation(std::strerror(errno));
    }

    this->_stream.seekg(0);
    tmp << this->_stream.rdbuf();
    return tmp.str();
}

void File::open(std::string fpath)
{
    if (this->_stream.is_open()) {
        this->_stream.close();
    }

    this->_stream.open(fpath);
}
