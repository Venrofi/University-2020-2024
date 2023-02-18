package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.asLiveData
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.repositories.SubjectRepository
import kotlinx.coroutines.launch

class SubjectListViewModel(private val _context: Context) : ViewModel() {
    private val _subjectRepository =
        SubjectRepository(AppDatabase.getInstance(_context).subjectDao())

    private val _subjects: LiveData<List<Subject>> = _subjectRepository.subjects.asLiveData()
    val subjects: LiveData<List<Subject>>
        get() = _subjects

    fun deleteSubject(subject: Subject) = viewModelScope.launch {
        _subjectRepository.deleteSubject(subject)
    }

    fun deleteSubjectWithStudentsById(id: Long) = viewModelScope.launch {
        _subjectRepository.deleteSubjectWithStudentsById(id)
    }

    fun deleteSubjectMarks(id: Long) = viewModelScope.launch {
        _subjectRepository.deleteSubjectMarks(id)
    }
}