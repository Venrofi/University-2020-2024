package com.example.teacherasistant.database

import androidx.room.Embedded
import androidx.room.Junction
import androidx.room.Relation
import com.example.teacherasistant.database.entities.Student
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.database.entities.SubjectStudentCrossRef

data class SubjectWithStudentsAndMarks(
    @Embedded val subject: Subject,
    @Relation(
        entity = Student::class,
        parentColumn = "id",
        entityColumn = "id",
        associateBy = Junction(
            SubjectStudentCrossRef::class,
            parentColumn = "subjectId",
            entityColumn = "studentId"
        )
    )
    val students: List<StudentWithMarks>
)
