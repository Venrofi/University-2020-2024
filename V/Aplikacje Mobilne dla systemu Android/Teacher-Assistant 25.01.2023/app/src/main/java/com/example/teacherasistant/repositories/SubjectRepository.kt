package com.example.teacherasistant.repositories

import com.example.teacherasistant.database.daos.SubjectDao
import com.example.teacherasistant.database.entities.Subject
import kotlinx.coroutines.flow.Flow

class SubjectRepository(private val _subjectDao: SubjectDao) {
    private val _subjects: Flow<List<Subject>> = _subjectDao.getAllSubjects()
    val subjects: Flow<List<Subject>>
        get() = _subjects

    suspend fun insertSubject(subject: Subject) = _subjectDao.insertSubject(subject)
    suspend fun deleteSubject(subject: Subject) = _subjectDao.deleteSubject(subject)
    suspend fun deleteSubjectWithStudentsById(id: Long) =
        _subjectDao.deleteSubjectWithStudentsById(id)

    suspend fun deleteSubjectMarks(id: Long) = _subjectDao.deleteSubjectMarks(id)
}