package com.example.teacherasistant.repositories

import com.example.teacherasistant.database.SubjectWithStudents
import com.example.teacherasistant.database.daos.SubjectDao
import com.example.teacherasistant.database.entities.SubjectStudentCrossRef
import kotlinx.coroutines.flow.Flow

class SubjectStudentRepository(private val _subjectDao: SubjectDao, subjectId: Long) {
    private val _subjectWithStudents: Flow<SubjectWithStudents> =
        _subjectDao.getSubjectWithStudentsById(subjectId)
    val subjectWithStudents: Flow<SubjectWithStudents>
        get() = _subjectWithStudents

    suspend fun insertSubjectWithStudent(subjectStudentCrossRef: SubjectStudentCrossRef) =
        _subjectDao.insertSubjectWithStudent(subjectStudentCrossRef)

    suspend fun deleteSubjectWithStudentByStudentId(subjectId: Long, studentId: Long) =
        _subjectDao.deleteSubjectWithStudentByStudentId(subjectId, studentId)

    suspend fun deleteSubjectStudentMarks(subjectId: Long, studentId: Long) =
        _subjectDao.deleteSubjectStudentMarks(subjectId, studentId)
}