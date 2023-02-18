package com.example.teacherasistant.database.entities

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "mark_table")
data class Mark(
    @PrimaryKey(autoGenerate = true) val id: Long?,
    @ColumnInfo(name = "student_id") val studentId: Long?,
    @ColumnInfo(name = "subject_id") val subjectId: Long?,
    @ColumnInfo(name = "value") val value: String?
)
