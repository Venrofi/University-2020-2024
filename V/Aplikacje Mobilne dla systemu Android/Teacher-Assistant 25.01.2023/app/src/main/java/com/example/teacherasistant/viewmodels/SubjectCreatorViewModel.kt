package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.repositories.SubjectRepository
import kotlinx.coroutines.launch

class SubjectCreatorViewModel(private val _context: Context) : ViewModel() {
    private val _subjectRepository =
        SubjectRepository(AppDatabase.getInstance(_context).subjectDao())

    fun insertSubject(subject: Subject) = viewModelScope.launch {
        _subjectRepository.insertSubject(subject)
    }
}