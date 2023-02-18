package com.example.teacherasistant.repositories

import com.example.teacherasistant.database.daos.MarkDao
import com.example.teacherasistant.database.daos.StudentDao
import com.example.teacherasistant.database.daos.SubjectDao

class AppRepository(
    private val _subjectDao: SubjectDao,
    private val _studentDao: StudentDao,
    private val _markDao: MarkDao
) {
    suspend fun deleteAllSubjects() = _subjectDao.deleteAllSubjects()
    suspend fun deleteAllSubjectsWithStudents() = _subjectDao.deleteAllSubjectsWithStudents()
    suspend fun deleteAllStudents() = _studentDao.deleteAllStudents()
    suspend fun deleteAllMarks() = _markDao.deleteAllMarks()
}