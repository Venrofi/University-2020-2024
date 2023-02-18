package com.example.teacherasistant.database.daos

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import androidx.room.Transaction
import com.example.teacherasistant.database.SubjectWithStudents
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.database.entities.SubjectStudentCrossRef
import kotlinx.coroutines.flow.Flow

@Dao
interface SubjectDao {
    @Query("SELECT * FROM subject_table")
    fun getAllSubjects(): Flow<List<Subject>>

    @Transaction
    @Query("SELECT * FROM subject_table WHERE id LIKE :id")
    fun getSubjectWithStudentsById(id: Long): Flow<SubjectWithStudents>

    @Insert
    suspend fun insertSubject(subject: Subject)

    @Insert
    suspend fun insertSubjectWithStudent(subjectStudentCrossRef: SubjectStudentCrossRef)

    @Delete
    suspend fun deleteSubject(subject: Subject)

    @Query("DELETE FROM subject_student_table WHERE subjectId LIKE :id")
    suspend fun deleteSubjectWithStudentsById(id: Long)

    @Query("DELETE FROM subject_student_table WHERE subjectId LIKE :subjectId AND studentId LIKE :studentId")
    suspend fun deleteSubjectWithStudentByStudentId(subjectId: Long, studentId: Long)

    @Query("DELETE FROM mark_table WHERE subject_id LIKE :subjectId AND student_id LIKE :studentId")
    suspend fun deleteSubjectStudentMarks(subjectId: Long, studentId: Long)

    @Query("DELETE FROM mark_table WHERE subject_id LIKE :id")
    suspend fun deleteSubjectMarks(id: Long)

    @Query("DELETE FROM subject_table")
    suspend fun deleteAllSubjects()

    @Query("DELETE FROM subject_student_table")
    suspend fun deleteAllSubjectsWithStudents()
}