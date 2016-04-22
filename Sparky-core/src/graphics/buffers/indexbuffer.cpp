#include "indexbuffer.h"

namespace sparky { namespace graphics {

    IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
        : m_Count(count)
    {
        glGenBuffers(1, &m_BufferID);
        this->bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
        this->unbind();
    }

    IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
        : m_Count(count)
    {
        glGenBuffers(1, &m_BufferID);
        this->bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
        this->unbind();
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_BufferID);
    }

    void IndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
    }

    void IndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} }