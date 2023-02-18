package com.example.teacherasistant.repositories

import com.example.teacherasistant.database.daos.StudentDao
import com.example.teacherasistant.database.entities.Student
import kotlinx.coroutines.flow.Flow

class StudentRepository(private val _studentDao: StudentDao) {
    private val _students: Flow<List<Student>> = _studentDao.getAllStudents()
    val students: Flow<List<Student>>
        get() = _students

    suspend fun insertStudent(student: Student): Long = _studentDao.insertStudent(student)
}