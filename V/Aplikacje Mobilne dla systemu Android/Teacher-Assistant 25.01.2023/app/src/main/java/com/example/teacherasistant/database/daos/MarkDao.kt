package com.example.teacherasistant.database.daos

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import com.example.teacherasistant.database.entities.Mark
import kotlinx.coroutines.flow.Flow

@Dao
interface MarkDao {
    @Query("SELECT * FROM mark_table WHERE subject_id LIKE :subjectId AND student_id LIKE :studentId")
    fun getMarksByIds(subjectId: Long, studentId: Long): Flow<List<Mark>>

    @Insert
    suspend fun insertMark(mark: Mark)

    @Delete
    suspend fun deleteMark(mark: Mark)

    @Query("DELETE FROM mark_table")
    suspend fun deleteAllMarks()
}