#include <vector>
#include "mesh.h"
#include <SDL2/SDL.h>
#include <iostream>

Mesh::Mesh()
{
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    GLfloat vertices[] = {
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f};

    GLint triangles[] = {0, 2, 3, 0, 3, 1,
                         2, 6, 7, 2, 7, 3,
                         6, 4, 5, 6, 5, 7,
                         4, 0, 1, 4, 1, 5,
                         1, 3, 7, 1, 7, 5,
                         4, 6, 2, 4, 2, 0};

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangles), triangles, GL_STATIC_DRAW);

    vertex_size = sizeof(triangles) / sizeof(GLint);
}

void Mesh::draw()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glDrawElements(GL_TRIANGLES, vertex_size, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
}
