package com.example.teacherasistant.repositories

import com.example.teacherasistant.database.daos.MarkDao
import com.example.teacherasistant.database.entities.Mark
import kotlinx.coroutines.flow.Flow

class MarkRepository(private val _markDao: MarkDao, subjectId: Long, studentId: Long) {
    private val _marks: Flow<List<Mark>> = _markDao.getMarksByIds(subjectId, studentId)
    val marks: Flow<List<Mark>>
        get() = _marks

    suspend fun insertMark(mark: Mark) = _markDao.insertMark(mark)
    suspend fun deleteMark(mark: Mark) = _markDao.deleteMark(mark)
}